/*
 * Copyright 2024 Free Software Foundation, Inc.
 *
 * This file is part of GNU Radio
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 *
 */

/***********************************************************************************/
/* This file is automatically generated using bindtool and can be manually edited  */
/* The following lines can be configured to regenerate this file during cmake      */
/* If manual edits are made, the following tags should be modified accordingly.    */
/* BINDTOOL_GEN_AUTOMATIC(0)                                                       */
/* BINDTOOL_USE_PYGCCXML(0)                                                        */
/* BINDTOOL_HEADER_FILE(dvb_config.h)                                        */
/* BINDTOOL_HEADER_FILE_HASH(360edb3daaa7586fc0628ced00de94cf)                     */
/***********************************************************************************/

#include <pybind11/complex.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

namespace py = pybind11;

#include <gnuradio/cemmse/dvb_config.h>
// pydoc.h is automatically generated in the build directory
#include <dvb_config_pydoc.h>

void bind_dvb_config(py::module& m)
{

    // using dvb_config    = gr::cemmse::dvb_config;
    // py::class_<dvb_config, gr::,
    //     std::shared_ptr<dvb_config>>(m, "dvb_config", D(dvb_config))
    //     .def(py::init(&dvb_config::make),
    //        D(dvb_config,make)
    //     );

    py::enum_<::gr::cemmse::dvb_code_rate_t>(m, "dvb_code_rate_t")
        .value("C1_2", ::gr::cemmse::dvb_code_rate_t::C1_2) // 0
        .value("C2_3", ::gr::cemmse::dvb_code_rate_t::C2_3) // 1
        .value("C3_4", ::gr::cemmse::dvb_code_rate_t::C3_4) // 2
        .value("C5_6", ::gr::cemmse::dvb_code_rate_t::C5_6) // 3
        .value("C7_8", ::gr::cemmse::dvb_code_rate_t::C7_8) // 4
        .export_values();

    py::implicitly_convertible<int, ::gr::cemmse::dvb_code_rate_t>();
    py::enum_<::gr::cemmse::dvb_constellation_t>(m, "dvb_constellation_t")
        .value("MOD_QPSK", ::gr::cemmse::dvb_constellation_t::MOD_QPSK)   // 0
        .value("MOD_16QAM", ::gr::cemmse::dvb_constellation_t::MOD_16QAM) // 1
        .value("MOD_64QAM", ::gr::cemmse::dvb_constellation_t::MOD_64QAM) // 2
        .export_values();

    py::implicitly_convertible<int, ::gr::cemmse::dvb_constellation_t>();
    py::enum_<::gr::cemmse::dvb_guardinterval_t>(m, "dvb_guardinterval_t")
        .value("GI_1_32", ::gr::cemmse::dvb_guardinterval_t::GI_1_32) // 0
        .value("GI_1_16", ::gr::cemmse::dvb_guardinterval_t::GI_1_16) // 1
        .value("GI_1_8", ::gr::cemmse::dvb_guardinterval_t::GI_1_8)   // 2
        .value("GI_1_4", ::gr::cemmse::dvb_guardinterval_t::GI_1_4)   // 3
        .export_values();

    py::implicitly_convertible<int, ::gr::cemmse::dvb_guardinterval_t>();


}








