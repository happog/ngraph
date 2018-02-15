// ----------------------------------------------------------------------------
// Copyright 2018 Nervana Systems Inc.
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// ----------------------------------------------------------------------------

#pragma once

#include "ngraph/node.hpp"
#include "ngraph/ops/op.hpp"
#include "ngraph/util.hpp"

#include <memory>

namespace ngraph
{
    namespace op
    {
        /// \brief Elementwise Relu operation for pattern matching.
        ///
        class Relu : public ngraph::op::UnaryElementwiseArithmetic
        {
        public:
            /// \brief Constructs an Relu operation.
            ///
            /// \param arg Node that produces the input tensor.
            Relu(std::shared_ptr<ngraph::Node> arg);

            virtual std::shared_ptr<Node> copy_with_new_args(
                const std::vector<std::shared_ptr<Node>>& new_args) const override;

            virtual void generate_adjoints(autodiff::Adjoints& adjoints,
                                           const std::shared_ptr<Node>& delta) override;
        };
    }
}