/* -*- c++ -*- */
/*
 * Copyright 2024 Lisallah.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef INCLUDED_CEMMSE_DVBT_CONFIG_H
#define INCLUDED_CEMMSE_DVBT_CONFIG_H

#include <gnuradio/cemmse/api.h>

namespace gr {
namespace cemmse {

// /*!
//  * \brief <+description+>
//  *
//  */
// class CEMMSE_API dvbt_config
// {
// public:
//     dvbt_config();
//     ~dvbt_config();

// private:
// };

enum dvbt_hierarchy_t {
    NH = 0,
    ALPHA1,
    ALPHA2,
    ALPHA4,
};

enum dvbt_transmission_mode_t {
    T2k = 0,
    T8k = 1,
};

} // namespace cemmse
} // namespace gr

typedef gr::cemmse::dvbt_hierarchy_t dvbt_hierarchy_t;
typedef gr::cemmse::dvbt_transmission_mode_t dvbt_transmission_mode_t;

#endif /* INCLUDED_CEMMSE_DVBT_CONFIG_H */
