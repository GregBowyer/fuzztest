// Copyright 2022 The Centipede Authors.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      https://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "./centipede/centipede_callbacks.h"
#include "./centipede/centipede_default_callbacks.h"
#include "./centipede/centipede_interface.h"
#include "./centipede/config_file.h"
#include "./centipede/config_init.h"
#include "./centipede/environment.h"

int main(int argc, char** argv) {
  const auto leftover_argv = centipede::config::InitCentipede(
      argc, argv, centipede::config::InitRuntime);

  centipede::Environment env{leftover_argv};
  centipede::DefaultCallbacksFactory<centipede::CentipedeDefaultCallbacks>
      callbacks;
  return CentipedeMain(env, callbacks);
}
