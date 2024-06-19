/* -*- c++ -*- */
/*
 * Copyright 2024 Lisallah.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef INCLUDED_CEMMSE_REFSIGNALS_H
#define INCLUDED_CEMMSE_REFSIGNALS_H

#include <gnuradio/block.h>
#include <gnuradio/cemmse/api.h>
#include <gnuradio/cemmse/dvbt_config.h>
#include <gnuradio/cemmse/dvb_config.h>

namespace gr {
namespace cemmse {

/*!
 * \brief Reference signals generator.
 * \ingroup cemmse
 *
 * ETSI EN 300 744 Clause 4.5 \n
 * Data input format: \n
 * complex(real(float), imag(float)). \n
 * Data output format: \n
 * complex(real(float), imag(float)).
 */
class CEMMSE_API refsignals : virtual public gr::block
{
public:
    typedef std::shared_ptr<refsignals> sptr;

    /*!
     * \brief Create Reference signals generator.
     *
     * \param itemsize size of an in/out item. \n
     * \param ninput input stream length. \n
     * \param noutput output stream length. \n
     * \param snr signal-to-noise ratio value \n
     * \param constellation constellation used. \n
     * \param hierarchy hierarchy used. \n
     * \param code_rate_HP high priority stream code rate. \n
     * \param code_rate_LP low priority stream code rate. \n
     * \param guard_interval guard interval used. \n
     * \param transmission_mode transmission mode used. \n
     * \param include_cell_id include or not Cell ID. \n
     * \param cell_id value of the CTo solve the problem, we need to include the header file that declares the ref_signals_impl class.ell ID.
     */
    static sptr make(int itemsize,
                     int ninput,
                     int noutput,
                     float snr,
                     dvb_constellation_t constellation,
                     dvbt_hierarchy_t hierarchy,
                     dvb_code_rate_t code_rate_HP,
                     dvb_code_rate_t code_rate_LP,
                     dvb_guardinterval_t guard_interval,
                     dvbt_transmission_mode_t transmission_mode,
                     int include_cell_id,
                     int cell_id);
};

} // namespace cemmse
} // namespace gr

#endif /* INCLUDED_CEMMSE_REFSIGNALS_H */
