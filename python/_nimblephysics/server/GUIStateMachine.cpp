/*
 * Copyright (c) 2011-2019, The DART development contributors
 * All rights reserved.
 *
 * The list of contributors can be found at:
 *   https://github.com/dartsim/dart/blob/master/LICENSE
 *
 * This file is provided under the following "BSD-style" License:
 *   Redistribution and use in source and binary forms, with or
 *   without modification, are permitted provided that the following
 *   conditions are met:
 *   * Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *   * Redistributions in binary form must reproduce the above
 *     copyright notice, this list of conditions and the following
 *     disclaimer in the documentation and/or other materials provided
 *     with the distribution.
 *   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND
 *   CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES,
 *   INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 *   MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 *   DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR
 *   CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 *   SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 *   LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF
 *   USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 *   AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 *   LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 *   ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 *   POSSIBILITY OF SUCH DAMAGE.
 */

#include <Python.h>
#include <dart/server/GUIStateMachine.hpp>
#include <dart/simulation/World.hpp>
#include <pybind11/eigen.h>
#include <pybind11/functional.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

namespace py = pybind11;

namespace dart {
namespace python {

void GUIStateMachine(py::module& m)
{
  ::py::class_<
      dart::server::GUIStateMachine,
      std::shared_ptr<dart::server::GUIStateMachine>>(m, "GUIStateMachine")
      .def(::py::init<>())
      .def("clear", &dart::server::GUIStateMachine::clear)
      .def(
          "createBox",
          &dart::server::GUIStateMachine::createBox,
          ::py::arg("key"),
          ::py::arg("size") = Eigen::Vector3s::Ones(),
          ::py::arg("pos") = Eigen::Vector3s::Zero(),
          ::py::arg("euler") = Eigen::Vector3s::Zero(),
          ::py::arg("color") = Eigen::Vector3s::Ones() * 0.5,
          ::py::arg("castShadows") = true,
          ::py::arg("receiveShadows") = false)
      .def(
          "createSphere",
          &dart::server::GUIStateMachine::createSphere,
          ::py::arg("key"),
          ::py::arg("radius") = 0.5,
          ::py::arg("pos") = Eigen::Vector3s::Zero(),
          ::py::arg("color") = Eigen::Vector3s::Ones() * 0.5,
          ::py::arg("castShadows") = true,
          ::py::arg("receiveShadows") = false)
      .def(
          "createLine",
          &dart::server::GUIStateMachine::createLine,
          ::py::arg("key"),
          ::py::arg("points"),
          ::py::arg("color") = Eigen::Vector3s::Ones() * 0.5)
      .def(
          "createMeshFromShape",
          &dart::server::GUIStateMachine::createMeshFromShape,
          ::py::arg("key"),
          ::py::arg("mesh"),
          ::py::arg("pos") = Eigen::Vector3s::Zero(),
          ::py::arg("euler") = Eigen::Vector3s::Zero(),
          ::py::arg("scale") = Eigen::Vector3s::Ones(),
          ::py::arg("color") = Eigen::Vector3s::Ones() * 0.5,
          ::py::arg("castShadows") = true,
          ::py::arg("receiveShadows") = false)
      .def(
          "getObjectPosition",
          &dart::server::GUIStateMachine::getObjectPosition,
          ::py::arg("key"))
      .def(
          "getObjectRotation",
          &dart::server::GUIStateMachine::getObjectRotation,
          ::py::arg("key"))
      .def(
          "getObjectColor",
          &dart::server::GUIStateMachine::getObjectColor,
          ::py::arg("key"))
      .def(
          "setObjectPosition",
          &dart::server::GUIStateMachine::setObjectPosition,
          ::py::arg("key"),
          ::py::arg("position"),
          ::py::call_guard<py::gil_scoped_release>())
      .def(
          "setObjectRotation",
          &dart::server::GUIStateMachine::setObjectRotation,
          ::py::arg("key"),
          ::py::arg("euler"))
      .def(
          "setObjectColor",
          &dart::server::GUIStateMachine::setObjectColor,
          ::py::arg("key"),
          ::py::arg("color"))
      .def(
          "deleteObject",
          &dart::server::GUIStateMachine::deleteObject,
          ::py::arg("key"))
      .def(
          "createText",
          &dart::server::GUIStateMachine::createText,
          ::py::arg("key"),
          ::py::arg("contents"),
          ::py::arg("fromTopLeft"),
          ::py::arg("size"))
      .def(
          "createButton",
          &dart::server::GUIStateMachine::createButton,
          ::py::arg("key"),
          ::py::arg("label"),
          ::py::arg("fromTopLeft"),
          ::py::arg("size"),
          ::py::arg("onClick"))
      .def(
          "createSlider",
          &dart::server::GUIStateMachine::createSlider,
          ::py::arg("key"),
          ::py::arg("fromTopLeft"),
          ::py::arg("size"),
          ::py::arg("min"),
          ::py::arg("max"),
          ::py::arg("value"),
          ::py::arg("onlyInts"),
          ::py::arg("horizontal"),
          ::py::arg("onChange"))
      .def(
          "createPlot",
          &dart::server::GUIStateMachine::createPlot,
          ::py::arg("key"),
          ::py::arg("fromTopLeft"),
          ::py::arg("size"),
          ::py::arg("xs"),
          ::py::arg("minX"),
          ::py::arg("maxX"),
          ::py::arg("ys"),
          ::py::arg("minY"),
          ::py::arg("maxY"),
          ::py::arg("plotType"))
      .def(
          "setUIElementPosition",
          &dart::server::GUIStateMachine::setUIElementPosition,
          ::py::arg("key"),
          ::py::arg("position"))
      .def(
          "setUIElementSize",
          &dart::server::GUIStateMachine::setUIElementSize,
          ::py::arg("key"),
          ::py::arg("size"))
      .def(
          "deleteUIElement",
          &dart::server::GUIStateMachine::deleteUIElement,
          ::py::arg("key"))
      .def(
          "setTextContents",
          &dart::server::GUIStateMachine::setTextContents,
          ::py::arg("key"),
          ::py::arg("contents"))
      .def(
          "setButtonLabel",
          &dart::server::GUIStateMachine::setButtonLabel,
          ::py::arg("key"),
          ::py::arg("label"))
      .def(
          "setSliderValue",
          &dart::server::GUIStateMachine::setSliderValue,
          ::py::arg("key"),
          ::py::arg("value"))
      .def(
          "setSliderMin",
          &dart::server::GUIStateMachine::setSliderMin,
          ::py::arg("key"),
          ::py::arg("value"))
      .def(
          "setSliderMax",
          &dart::server::GUIStateMachine::setSliderMax,
          ::py::arg("key"),
          ::py::arg("value"))
      .def(
          "setPlotData",
          &dart::server::GUIStateMachine::setPlotData,
          ::py::arg("key"),
          ::py::arg("xs"),
          ::py::arg("minX"),
          ::py::arg("maxX"),
          ::py::arg("ys"),
          ::py::arg("minY"),
          ::py::arg("maxY"))
      .def(
          "renderWorld",
          &dart::server::GUIStateMachine::renderWorld,
          ::py::arg("world"),
          ::py::arg("prefix") = "world",
          ::py::arg("renderForces") = true,
          ::py::arg("renderForceMagnitudes") = true,
          ::py::call_guard<py::gil_scoped_release>())
      .def(
          "renderBasis",
          &dart::server::GUIStateMachine::renderBasis,
          ::py::arg("scale") = 10.0,
          ::py::arg("prefix") = "basis",
          ::py::arg("pos") = Eigen::Vector3s::Zero(),
          ::py::arg("euler") = Eigen::Vector3s::Zero(),
          ::py::call_guard<py::gil_scoped_release>())
      .def(
          "renderSkeleton",
          &dart::server::GUIStateMachine::renderSkeleton,
          ::py::arg("skeleton"),
          ::py::arg("prefix") = "world",
          ::py::arg("overrideColor") = -1 * Eigen::Vector3s::Ones(),
          ::py::call_guard<py::gil_scoped_release>())
      .def(
          "renderTrajectoryLines",
          &dart::server::GUIStateMachine::renderTrajectoryLines,
          ::py::arg("world"),
          ::py::arg("positions"),
          ::py::arg("prefix") = "trajectory",
          ::py::call_guard<py::gil_scoped_release>())
      .def(
          "renderBodyWrench",
          &dart::server::GUIStateMachine::renderBodyWrench,
          ::py::arg("body"),
          ::py::arg("wrench"),
          ::py::arg("scaleFactor") = 0.1,
          ::py::arg("prefix") = "wrench",
          ::py::call_guard<py::gil_scoped_release>())
      .def(
          "renderMovingBodyNodeVertices",
          &dart::server::GUIStateMachine::renderMovingBodyNodeVertices,
          ::py::arg("body"),
          ::py::arg("scaleFactor") = 0.1,
          ::py::arg("prefix") = "vert-vel",
          ::py::call_guard<py::gil_scoped_release>())
      .def(
          "clearBodyWrench",
          &dart::server::GUIStateMachine::clearBodyWrench,
          ::py::arg("body"),
          ::py::arg("prefix") = "wrench",
          ::py::call_guard<py::gil_scoped_release>());
}

} // namespace python
} // namespace dart
