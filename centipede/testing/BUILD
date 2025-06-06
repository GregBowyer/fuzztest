# Copyright 2022 The Centipede Authors.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#      https://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

load(":build_defs.bzl", "centipede_fuzz_target")

package(default_visibility = [
    "@com_google_fuzztest//centipede:__subpackages__",
])

licenses(["notice"])

exports_files([
    "centipede_main_test.sh",
    "multi_sanitizer_fuzz_target.cc",
])

################################################################################
#                        Fuzz targets for fuzz tests
################################################################################

centipede_fuzz_target(
    name = "abort_fuzz_target",
)

centipede_fuzz_target(
    name = "empty_fuzz_target",
)

centipede_fuzz_target(
    name = "expensive_startup_fuzz_target",
)

# Fuzz target that uses the C++ RunnerCallbacks API to return serialized config.
cc_binary(
    name = "_fuzz_target_with_config",
    srcs = ["fuzz_target_with_config.cc"],
    # Cannot be built directly - build :fuzz_target_with_config instead.
    tags = [
        "local",
        "manual",
        "notap",
    ],
    deps = [
        "@com_google_absl//absl/base:nullability",
        "@com_google_absl//absl/flags:flag",
        "@com_google_absl//absl/flags:parse",
        "@com_google_fuzztest//centipede:centipede_runner_no_main",
        "@com_google_fuzztest//common:defs",
    ],
)

centipede_fuzz_target(
    name = "fuzz_target_with_config",
    fuzz_target = "_fuzz_target_with_config",
)

# Fuzz target that uses the C++ RunnerCallbacks API to mutate inputs.
cc_binary(
    name = "_fuzz_target_with_custom_mutator",
    srcs = ["fuzz_target_with_custom_mutator.cc"],
    # Cannot be built directly - build :fuzz_target_with_custom_mutator instead.
    tags = [
        "local",
        "manual",
        "notap",
    ],
    deps = [
        "@com_google_absl//absl/base:nullability",
        "@com_google_absl//absl/flags:flag",
        "@com_google_absl//absl/flags:parse",
        "@com_google_fuzztest//centipede:centipede_runner_no_main",
        "@com_google_fuzztest//centipede:mutation_input",
        "@com_google_fuzztest//common:defs",
    ],
)

centipede_fuzz_target(
    name = "fuzz_target_with_custom_mutator",
    fuzz_target = "_fuzz_target_with_custom_mutator",
)

centipede_fuzz_target(
    name = "minimize_me_fuzz_target",
)

centipede_fuzz_target(
    name = "user_defined_features_target",
)

# Simple fuzz target used for testing.
centipede_fuzz_target(
    name = "test_fuzz_target",
)

# Dummy fuzz target that uses the C++ RunnerCallbacks API to return seed inputs.
cc_binary(
    name = "_seeded_fuzz_target",
    srcs = ["seeded_fuzz_target.cc"],
    # Cannot be built directly - build :seeded_fuzz_target instead.
    tags = [
        "local",
        "manual",
        "notap",
    ],
    deps = [
        "@com_google_absl//absl/base:nullability",
        "@com_google_fuzztest//centipede:centipede_runner_no_main",
        "@com_google_fuzztest//common:defs",
    ],
)

centipede_fuzz_target(
    name = "seeded_fuzz_target",
    fuzz_target = "_seeded_fuzz_target",
)

# Server binary for :external_target_test.
cc_binary(
    name = "_external_target_server",
    srcs = ["external_target_server.cc"],
    # Cannot be built directly - build :external_target_server instead.
    tags = [
        "local",
        "manual",
        "notap",
    ],
    deps = [
        "@com_google_absl//absl/log:check",
        "@com_google_absl//absl/strings",
        "@com_google_fuzztest//centipede:centipede_runner_no_main",
    ],
)

centipede_fuzz_target(
    name = "external_target_server",
    fuzz_target = "_external_target_server",
)

cc_binary(
    name = "_external_target",
    srcs = ["external_target.cc"],
    # Cannot be built directly - build :external_target instead.
    tags = [
        "local",
        "manual",
        "notap",
    ],
    deps = [
        "@com_google_absl//absl/base:nullability",
        "@com_google_absl//absl/log:check",
        "@com_google_absl//absl/strings",
        "@com_google_fuzztest//centipede:centipede_runner_no_main",
        "@com_google_fuzztest//common:defs",
    ],
)

centipede_fuzz_target(
    name = "external_target",
    fuzz_target = "_external_target",
)

# Target instrumented with -fsanitize-coverage=trace-pc.
centipede_fuzz_target(
    name = "test_fuzz_target_trace_pc",
    srcs = ["test_fuzz_target.cc"],
    sancov = "trace-pc",
)

# Target built with non-pie.
centipede_fuzz_target(
    name = "test_fuzz_target_non_pie",
    srcs = ["test_fuzz_target.cc"],
    linkopts = ["-no-pie"],
)

# Target instrumented with -fsanitize-coverage=trace-pc.
centipede_fuzz_target(
    name = "abort_fuzz_target_trace_pc",
    srcs = ["abort_fuzz_target.cc"],
    sancov = "trace-pc",
)

# Target instrumented with -fsanitize-coverage=inline-8bit-counters.
centipede_fuzz_target(
    name = "abort_fuzz_target_inline_8bit_counters",
    srcs = ["abort_fuzz_target.cc"],
    sancov = "inline-8bit-counters,pc-table",
)

# Test fuzz target with lots of threads.
centipede_fuzz_target(
    name = "threaded_fuzz_target",
    sancov = "trace-pc-guard",  # Only this instrumentation to ensure it works.
)

# Target for clusterfuzz format tests.
centipede_fuzz_target(
    name = "clusterfuzz_format_target",
)

# Target for clusterfuzz format tests instrumented with AddressSanitizer.
centipede_fuzz_target(
    name = "clusterfuzz_format_sanitized_target",
    srcs = ["clusterfuzz_format_target.cc"],
    copts = ["-fsanitize=address"],
    linkopts = ["-fsanitize=address"],
)

# Helper DSO for :multi_dso_target
cc_library(
    name = "multi_dso_target_lib",
    srcs = ["multi_dso_target_lib.cc"],
    hdrs = ["multi_dso_target_lib.h"],
    copts = [
        "-fsanitize-coverage=trace-pc-guard,pc-table,control-flow",
        "-gline-tables-only",
    ],
)

cc_shared_library(
    name = "multi_dso_target_shared_lib",
    user_link_flags = select(
        {
            "@platforms//os:macos": [
                # For compatible behavior on weak symbols.
                "-Wl,-undefined,dynamic_lookup",
            ],
            "//conditions:default": [],
        },
    ),
    deps = [":multi_dso_target_lib"],
)

# A fuzz target with an instrumented DSO dependency (:multi_dso_target_lib).
cc_binary(
    name = "multi_dso_target",
    srcs = ["multi_dso_target_main.cc"],
    copts = [
        "-fsanitize-coverage=trace-pc-guard,pc-table,control-flow",
        "-gline-tables-only",
    ],
    dynamic_deps = [
        ":multi_dso_target_shared_lib",
    ],
    deps = [
        ":multi_dso_target_lib",
        "@com_google_fuzztest//centipede:centipede_runner",
    ],
)

# Helper DSO for :data_only_dso_target
cc_library(
    name = "data_only_dso_target_lib",
    srcs = ["data_only_dso_target_lib.cc"],
    hdrs = ["data_only_dso_target_lib.h"],
    copts = [
        "-fsanitize-coverage=trace-pc-guard,pc-table,control-flow",
        "-gline-tables-only",
    ],
    linkopts = ["-Wl,-gc-sections"],
)

# A fuzz target with an instrumented data-only DSO dependency (:data_only_dso_target_lib).
cc_binary(
    name = "data_only_dso_target",
    srcs = ["data_only_dso_target_main.cc"],
    copts = [
        "-fsanitize-coverage=trace-pc-guard,pc-table,trace-cmp",
        "-gline-tables-only",
    ],
    linkstatic = False,
    deps = [
        ":data_only_dso_target_lib",
        "@com_google_fuzztest//centipede:centipede_runner",
    ],
)

# A standalone binary with main() that is worth fuzzing.
cc_binary(
    name = "standalone_fuzz_target_with_main",
    srcs = ["standalone_fuzz_target_with_main.cc"],
    deps = ["@com_google_absl//absl/base:nullability"],
)

################################################################################
# This fuzz target is not currently used by any automated tests and is here for
# manual tests only.
################################################################################

centipede_fuzz_target(
    name = "multi_sanitizer_fuzz_target",
)

################################################################################
#                       Helper binaries for fuzz tests
################################################################################

sh_binary(
    name = "test_input_filter",
    srcs = ["test_input_filter.sh"],
)

################################################################################
#                                 Fuzz tests
################################################################################

# Runs common Centipede scenarios with local files.
sh_test(
    name = "centipede_main_test",
    timeout = "long",
    srcs = ["centipede_main_test.sh"],
    data = [
        ":abort_fuzz_target",
        ":test_fuzz_target",
        "@com_google_fuzztest//centipede",
        "@com_google_fuzztest//centipede:test_fuzzing_util_sh",
        "@com_google_fuzztest//centipede:test_util_sh",
    ],
)

sh_test(
    name = "runner_test",
    srcs = ["runner_test.sh"],
    data = [
        ":test_fuzz_target",
        ":test_fuzz_target_non_pie",
        "@com_google_fuzztest//centipede:test_util_sh",
    ],
)

sh_test(
    name = "instrumentation_test",
    srcs = ["instrumentation_test.sh"],
    data = [
        ":empty_fuzz_target",
        "@com_google_fuzztest//centipede:test_util_sh",
    ],
)

sh_test(
    name = "dump_binary_info_test",
    srcs = ["dump_binary_info_test.sh"],
    data = [
        ":multi_dso_target",
        "@com_google_fuzztest//centipede:test_util_sh",
    ],
)

sh_test(
    name = "multi_dso_test",
    srcs = ["multi_dso_test.sh"],
    data = [
        ":multi_dso_target",
        "@com_google_fuzztest//centipede",
        "@com_google_fuzztest//centipede:test_util_sh",
    ],
)

sh_test(
    name = "data_only_dso_test",
    srcs = ["data_only_dso_test.sh"],
    data = [
        ":data_only_dso_target",
        "@com_google_fuzztest//centipede",
        "@com_google_fuzztest//centipede:test_util_sh",
    ],
)

sh_test(
    name = "trace_pc_test",
    srcs = ["trace_pc_test.sh"],
    data = [
        ":abort_fuzz_target_trace_pc",
        "@com_google_fuzztest//centipede",
        "@com_google_fuzztest//centipede:test_util_sh",
    ],
)

sh_test(
    name = "inline_8bit_counters_test",
    srcs = ["inline_8bit_counters_test.sh"],
    data = [
        ":abort_fuzz_target_inline_8bit_counters",
        "@com_google_fuzztest//centipede",
        "@com_google_fuzztest//centipede:test_util_sh",
    ],
)

sh_test(
    name = "minimize_crash_test",
    srcs = ["minimize_crash_test.sh"],
    data = [
        ":minimize_me_fuzz_target",
        "@com_google_fuzztest//centipede",
        "@com_google_fuzztest//centipede:test_util_sh",
    ],
)

sh_test(
    name = "user_defined_features_test",
    srcs = ["user_defined_features_test.sh"],
    data = [
        ":user_defined_features_target",
        "@com_google_fuzztest//centipede",
        "@com_google_fuzztest//centipede:test_util_sh",
    ],
)

sh_test(
    name = "no_startup_features_test",
    srcs = ["no_startup_features_test.sh"],
    data = [
        ":expensive_startup_fuzz_target",
        "@com_google_fuzztest//centipede",
        "@com_google_fuzztest//centipede:test_util_sh",
    ],
)

# Runs Centipede and check its output format.
sh_test(
    name = "clusterfuzz_format_test",
    srcs = ["clusterfuzz_format_test.sh"],
    data = [
        "clusterfuzz_format_sanitized_target",
        "clusterfuzz_format_target",
        "@com_google_fuzztest//centipede",
        "@com_google_fuzztest//centipede:test_util_sh",
    ],
)

sh_test(
    name = "external_target_test",
    srcs = ["external_target_test.sh"],
    data = [
        ":external_target",
        ":external_target_server",
        "@com_google_fuzztest//centipede",
        "@com_google_fuzztest//centipede:test_util_sh",
    ],
)
