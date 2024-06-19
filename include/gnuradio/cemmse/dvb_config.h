/* -*- c++ -*- */
/*
 * Copyright 2024 Lisallah.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef INCLUDED_CEMMSE_DVB_CONFIG_H
#define INCLUDED_CEMMSE_DVB_CONFIG_H

#include <gnuradio/cemmse/api.h>

namespace gr {
namespace cemmse {

// /*!
//  * \brief <+description+>
//  *
//  */
// class CEMMSE_API dvb_config
// {
// public:
//     dvb_config();
//     ~dvb_config();

// private:
// };

enum dvb_code_rate_t {
    C1_2 = 0,
    C2_3,
    C3_4,
    C5_6,
    C7_8,
};

enum dvb_constellation_t {
    MOD_QPSK = 0,
    MOD_16QAM,
    MOD_64QAM,
};

enum dvb_guardinterval_t {
    GI_1_32 = 0,
    GI_1_16,
    GI_1_8,
    GI_1_4,
};

} // namespace cemmse
} // namespace gr

typedef gr::cemmse::dvb_code_rate_t dvb_code_rate_t;
typedef gr::cemmse::dvb_constellation_t dvb_constellation_t;
typedef gr::cemmse::dvb_guardinterval_t dvb_guardinterval_t;

#endif /* INCLUDED_CEMMSE_DVB_CONFIG_H */
