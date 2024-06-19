/* -*- c++ -*- */
/*
 * Copyright 2024 Lisallah.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef INCLUDED_CEMMSE_DEMOD_REFSIGNALS_IMPL_H
#define INCLUDED_CEMMSE_DEMOD_REFSIGNALS_IMPL_H

#include <gnuradio/cemmse/demod_refsignals.h>
#include "refsignals_impl.h"

namespace gr {
namespace cemmse {

class demod_refsignals_impl : public demod_refsignals
{
// configuration object for this class
const dvbt_configure config;
private:
    // Pilot Generator object
    dvbt_pilot_gen d_pg;

    // In and Out data length
    int d_ninput;
    int d_noutput;

    int d_init;
    int d_fi_start;

    int is_sync_start(int nitems);

public:
    demod_refsignals_impl(int itemsize,
        int ninput,
        int noutput,
        // float snr,
        dvb_constellation_t constellation,
        dvbt_hierarchy_t hierarchy,
        dvb_code_rate_t code_rate_HP,
        dvb_code_rate_t code_rate_LP,
        dvb_guardinterval_t guard_interval,
        dvbt_transmission_mode_t transmission_mode = gr::cemmse::T2k,
        int include_cell_id = 0,
        int cell_id = 0);
    ~demod_refsignals_impl() override;

    // Where all the action really happens
    void forecast(int noutput_items, gr_vector_int& ninput_items_required) override;

    int general_work(int noutput_items,
                     gr_vector_int& ninput_items,
                     gr_vector_const_void_star& input_items,
                     gr_vector_void_star& output_items) override;
};

} // namespace cemmse
} // namespace gr

#endif /* INCLUDED_CEMMSE_DEMOD_REFSIGNALS_IMPL_H */
