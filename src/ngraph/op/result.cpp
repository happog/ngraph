/*******************************************************************************
* Copyright 2017-2018 Intel Corporation
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*     http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*******************************************************************************/

#include <memory>
#include <typeindex>
#include <typeinfo>
#include "ngraph/node.hpp"

#include "ngraph/op/result.hpp"

using namespace std;
using namespace ngraph;

op::Result::Result(const std::shared_ptr<Node>& arg)
    : RequiresTensorViewArgs("Result", {arg})
{
    if (arg->get_outputs().size() != 1)
    {
        throw ngraph_error("Expected a single-output argument");
    }

    //always borrow the placement conf even the default one
    set_placement(arg->get_placement());
    set_value_type_checked(arg->get_element_type(), arg->get_shape());
}

op::Result::Result(const Result& other, const NodeVector& new_args)
    : RequiresTensorViewArgs(other, new_args)
{
    if (new_args.size() != 1)
    {
        throw ngraph_error("Incorrect number of new arguments");
    }

    if (new_args.at(0)->get_outputs().size() != 1)
    {
        throw ngraph_error("Expected a single-output argument");
    }
}
