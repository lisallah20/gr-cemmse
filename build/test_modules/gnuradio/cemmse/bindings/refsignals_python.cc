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
/* BINDTOOL_HEADER_FILE(refsignals.h)                                        */
/* BINDTOOL_HEADER_FILE_HASH(447d5f421da6be223163e7e9bb3af4c5)                     */
/***********************************************************************************/

#include <pybind11/complex.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

namespace py = pybind11;

#include <gnuradio/cemmse/refsignals.h>
// pydoc.h is automatically generated in the build directory
#include <refsignals_pydoc.h>

void bind_refsignals(py::module& m)
{

    using refsignals    = gr::cemmse::refsignals;

    py::class_<refsignals, gr::block, gr::basic_block,
        std::shared_ptr<refsignals>>(m, "refsignals", D(refsignals))

        .def(py::init(&refsignals::make),
           py::arg("itemsize"),
           py::arg("ninput"),
           py::arg("noutput"),
           py::arg("snr"),
           py::arg("constellation"),
           py::arg("hierarchy"),
           py::arg("code_rate_HP"),
           py::arg("code_rate_LP"),
           py::arg("guard_interval"),
           py::arg("transmission_mode"),
           py::arg("include_cell_id"),
           py::arg("cell_id"),
           D(refsignals,make)
        );

}