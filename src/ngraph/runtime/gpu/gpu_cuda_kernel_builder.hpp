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

#pragma once

#include <array>
#include <set>
#include <string>
#include <vector>

namespace ngraph
{
    namespace codegen
    {
        class CodeWriter;
    }
    namespace runtime
    {
        namespace gpu
        {
            class CudaKernelBuilder
            {
            public:
                static void get_elementwise_op(codegen::CodeWriter& writer,
                                               const std::string& name,
                                               const std::string& op,
                                               const std::vector<std::string>& data_types);

                static void get_broadcast_op(codegen::CodeWriter& writer,
                                             const std::string& name,
                                             const std::array<std::string, 2>& data_types,
                                             const size_t rank);

                static void get_concat_op(codegen::CodeWriter& writer,
                                          const std::string& name,
                                          const std::vector<std::string>& data_types,
                                          size_t num_inputs);

                static void get_onehot_op(codegen::CodeWriter& writer,
                                          const std::string& name,
                                          const std::array<std::string, 2>& data_types);

                static void get_reshape_op(codegen::CodeWriter& writer,
                                           const std::string& name,
                                           const std::array<std::string, 2>& data_types);

                static void get_slice_op(codegen::CodeWriter& writer,
                                         const std::string& name,
                                         const std::array<std::string, 2>& data_types);

                static void get_reverse_op(codegen::CodeWriter& writer,
                                           const std::string& name,
                                           const std::array<std::string, 2>& data_types);

                static void get_replace_slice_op(codegen::CodeWriter& writer,
                                                 const std::string& name,
                                                 const std::array<std::string, 3>& data_types,
                                                 int nthreads_per_block);

                static void get_reduce_window_op(codegen::CodeWriter& writer,
                                                 const std::string& name,
                                                 const std::string& op,
                                                 const std::vector<std::string>& data_types,
                                                 const size_t rank);

                static void get_reverse_sequence_op(codegen::CodeWriter& writer,
                                                    const std::string& name,
                                                    const std::array<std::string, 3>& data_types,
                                                    const size_t batch_axis,
                                                    const size_t sequence_axis,
                                                    const size_t rank);

                static void get_device_helper(codegen::CodeWriter& writer,
                                              const std::string& name,
                                              const std::string& math_kernel,
                                              const std::vector<std::string>& data_types);

                static void get_pad_dynamic_op(codegen::CodeWriter& writer,
                                               const std::string& name,
                                               const std::array<std::string, 2>& data_types);

                static void get_ew_collective_op(codegen::CodeWriter& writer,
                                                 const std::string& name,
                                                 const std::string& op,
                                                 const std::string& reduce_op,
                                                 const std::vector<std::string>& data_types,
                                                 const std::set<size_t>& reduced_tensors,
                                                 bool save_elementwise,
                                                 size_t rank);

                static void add_pod_typedefs(codegen::CodeWriter& writer);

                /// \brief Given kernel input variables i_* produce register variables o_coordinates{i}
                ///        of the non-reduced tensor and return the string name of integer index into reduced tensor
                static std::string
                    collective_coordinate_transform_helper(codegen::CodeWriter& writer,
                                                           std::string i_thread_index,
                                                           std::string i_strides,
                                                           std::string i_stride_magic,
                                                           std::string i_stride_shift,
                                                           std::string i_reduced_strides,
                                                           std::string o_coordinates,
                                                           size_t rank);
            };
        }
    }
}
