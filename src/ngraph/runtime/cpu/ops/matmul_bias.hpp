/*******************************************************************************
* Copyright 2018 Intel Corporation
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

#pragma once

#include "ngraph/node.hpp"
#include "ngraph/ops/op.hpp"
#include "ngraph/util.hpp"

#include <memory>

namespace ngraph
{
    namespace op
    {
        class MatmulBias : public RequiresTensorViewArgs
        {
        public:
            MatmulBias(std::shared_ptr<Node> W,
                       std::shared_ptr<Node> x,
                       std::shared_ptr<Node> b,
                       Shape shape_w,
                       Shape shape_x,
                       bool transpose_w,
                       bool transpose_x);

            bool get_is_arg0_transposed() const { return m_transpose_w; }
            bool get_is_arg1_transposed() const { return m_transpose_x; }
            Shape get_arg0_shape() const { return m_shape_w; }
            Shape get_arg1_shape() const { return m_shape_x; }
            virtual std::shared_ptr<Node> copy_with_new_args(
                const std::vector<std::shared_ptr<Node>>& new_args) const override;

        private:
            Shape m_shape_w;
            Shape m_shape_x;
            bool m_transpose_w;
            bool m_transpose_x;
        };
    }
}