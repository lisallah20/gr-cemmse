/* -*- c++ -*- */
/*
 * Copyright 2024 Lisallah.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef INCLUDED_CEMMSE_REFSIGNALS_IMPL_H
#define INCLUDED_CEMMSE_REFSIGNALS_IMPL_H

#include <gnuradio/cemmse/refsignals.h>
#include <gnuradio/cemmse/dvbt_configure.h>
#include <gnuradio/fft/fft.h>
#include <deque>
#include <vector>

// This should eventually go into a const file
constexpr int SYMBOLS_PER_FRAME = 68;
constexpr int FRAMES_PER_SUPERFRAME = 4;

constexpr int SCATTERED_PILOT_SIZE_2k = 142;
constexpr int CONTINUAL_PILOT_SIZE_2k = 45;
constexpr int TPS_PILOT_SIZE_2k = 17;

constexpr int SCATTERED_PILOT_SIZE_8k = 568;
constexpr int CONTINUAL_PILOT_SIZE_8k = 177;
constexpr int TPS_PILOT_SIZE_8k = 68;

namespace gr {
namespace cemmse {

class dvbt_pilot_gen
{
private:
    // this should be first in order to be initialized first
    const dvbt_configure& config;

    const int d_Kmin;
    const int d_Kmax;
    const int d_fft_length;
    const int d_payload_length;
    const int d_zeros_on_left;
    const int d_zeros_on_right;
    const int d_cp_length;

    static const int d_symbols_per_frame;
    static const int d_frames_per_superframe;
    static const float d_snr;

    // 2k mode
    // scattered pilot carriers info
    static const int d_spilot_carriers_size_2k;

    // continual pilot carriers info
    static const int d_cpilot_carriers_size_2k;
    static const int d_cpilot_carriers_2k[];

    // TPS carriers info
    static const int d_tps_carriers_size_2k;
    static const int d_tps_carriers_2k[];

    // 8k mode
    // scattered pilot carriers info
    static const int d_spilot_carriers_size_8k;

    // continual pilot carriers info
    static const int d_cpilot_carriers_size_8k;
    static const int d_cpilot_carriers_8k[];

    // TPS carriers info
    static const int d_tps_carriers_size_8k;
    static const int d_tps_carriers_8k[];

    // TPS sync data
    static const int d_tps_sync_size;
    static const int d_tps_sync_even[];
    static const int d_tps_sync_odd[];

    // Variables to keep data for 2k, 8k, 4k
    int d_spilot_carriers_size;
    volk::vector<gr_complex> d_spilot_carriers_val;
    volk::vector<gr_complex> d_channel_gain;

    int d_cpilot_carriers_size;
    const int* d_cpilot_carriers;
    volk::vector<float> d_known_phase_diff;
    volk::vector<float> d_cpilot_phase_diff;
    int d_freq_offset = 0;
    float d_carrier_freq_correction = 0.0;
    float d_sampling_freq_correction = 0.0;

    // Variable to keep corrected OFDM symbol
    volk::vector<gr_complex> d_derot_in;

    int d_tps_carriers_size;
    const int* d_tps_carriers;
    volk::vector<gr_complex> d_tps_carriers_val;

    // Keeps TPS data
    volk::vector<unsigned char> d_tps_data;
    // Keep TPS carriers values from previous symbol
    volk::vector<gr_complex> d_prev_tps_symbol;
    // Keep TPS carriers values from current symbol
    volk::vector<gr_complex> d_tps_symbol;
    // Keeps the rcv TPS data, is a FIFO
    std::deque<char> d_rcv_tps_data;
    // Keeps the TPS sync sequence
    std::deque<char> d_tps_sync_evenv;
    std::deque<char> d_tps_sync_oddv;

    // Keeps channel estimation carriers
    // we use both continual and scattered carriers
    volk::vector<int> d_chanestim_carriers;

    // Keeps paload carriers
    volk::vector<int> d_payload_carriers;

    // Indexes for all carriers
    int d_spilot_index = 0;
    int d_cpilot_index = 0;
    int d_tpilot_index = 0;
    int d_symbol_index = 0;
    int d_symbol_index_known = 0;
    int d_frame_index = 0;
    int d_superframe_index = 0;
    int d_freq_offset_max = 8;
    int d_trigger_index = 0;
    int d_payload_index = 0;
    int d_chanestim_index = 0;
    int d_prev_mod_symbol_index = 0;
    int d_mod_symbol_index = 0;
    int d_equalizer_ready;

    // PRPS generator data buffer
    std::vector<char> d_wk;
    // Generate PRBS
    void generate_prbs();

    // TPS private methods
    void set_tps_bits(int start, int stop, unsigned int data);

    void set_symbol_index(int index);
    int get_symbol_index();
    void set_tps_data();
    void get_tps_data();

    void reset_pilot_generator();

    // Scattered pilot generator methods
    int get_current_spilot(int spilot) const;
    gr_complex get_spilot_value(int spilot);
    void set_spilot_value(int spilot, gr_complex val);
    void advance_spilot(int sindex);
    // Methods used to quick iterate through all spilots
    int get_first_spilot();
    int get_last_spilot() const;
    int get_next_spilot();
    // Scattered pilot data processing method
    int process_spilot_data(const gr_complex* in, float snr);
    // int process_spilot_data(const gr_complex* in);

    // Channel estimation methods
    void set_channel_gain(int spilot, gr_complex val, float snr);
    // void set_channel_gain(int spilot, gr_complex val);

    // Continual pilot generator methods
    int get_current_cpilot() const;
    gr_complex get_cpilot_value(int cpilot);
    void advance_cpilot();
    // Continual pilot data processing methods
    void process_cpilot_data(const gr_complex* in);
    void compute_oneshot_csft(const gr_complex* in);
    gr_complex* frequency_correction(const gr_complex* in, gr_complex* out);

    // TPS generator methods
    int get_current_tpilot() const;
    gr_complex get_tpilot_value(int tpilot);
    void advance_tpilot();
    // TPS data
    void format_tps_data();
    // Encode TPS data
    void generate_bch_code();
    // Verify parity on TPS data
    int verify_bch_code(std::deque<char> data);
    // TPS data processing methods
    int process_tps_data(const gr_complex* in, const int diff_symbo_index);

    // Channel estimation methods
    void set_chanestim_carrier(int k);

    // Payload data processing methods
    int get_current_payload();
    void advance_chanestim();
    void set_payload_carrier(int k);
    void advance_payload();
    void process_payload_data(const gr_complex* in, gr_complex* out);

public:
    gr::logger_ptr d_logger;
    gr::logger_ptr d_debug_logger;
    dvbt_pilot_gen(const dvbt_configure& config);
    ~dvbt_pilot_gen();

    float snr;
    
    /*!
     * ETSI EN 300 744 Clause 4.5. \n
     * Update a set of carriers with the pilot signals. \n
     */
    void update_output(const gr_complex* in, gr_complex* out);

    /*!
     * TODO
     * ETSI EN 300 744 Clause 4.5. \n
     * Extract data from a set of carriers using pilot signals. \n
     * This is doing frequency correction, equalization. \n
     */
    int parse_input(const gr_complex* in,
                    gr_complex* out,
                    int* symbol_index,
                    int* frame_index,
                    float snr);
};

// Batas kelas pilot generator

class refsignals_impl : public refsignals
{
const dvbt_configure config;
private:
    // Pilot Generator object
    dvbt_pilot_gen d_pg;

    // In and Out data length
    int d_ninput;
    int d_noutput;

    fft::fft_complex_rev ofdm_fft;
    int ofdm_fft_size;
    float normalization;

public:
    refsignals_impl(int itemsize,
                     int ninput,
                     int noutput,
                     float snr,
                     dvb_constellation_t constellation,
                     dvbt_hierarchy_t hierarchy,
                     dvb_code_rate_t code_rate_HP,
                     dvb_code_rate_t code_rate_LP,
                     dvb_guardinterval_t guard_interval,
                    //  dvbt_transmission_mode_t transmission_mode = gr::mmse_dvbt::T2k,
                     dvbt_transmission_mode_t transmission_mode = T2k,
                     int include_cell_id = 0,
                     int cell_id = 0);
    ~refsignals_impl() override;

    // Where all the action really happens
    void forecast(int noutput_items, gr_vector_int& ninput_items_required) override;

    int general_work(int noutput_items,
                     gr_vector_int& ninput_items,
                     gr_vector_const_void_star& input_items,
                     gr_vector_void_star& output_items) override;
};

} // namespace cemmse
} // namespace gr

#endif /* INCLUDED_CEMMSE_REFSIGNALS_IMPL_H */