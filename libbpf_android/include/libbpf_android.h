/*
 * Copyright (C) 2018 The Android Open Source Project
 * Android BPF library - public API
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef LIBBPF_SYSTEM_H
#define LIBBPF_SYSTEM_H

#include <libbpf.h>
#include <linux/bpf.h>

#include <string>
#include <vector>

namespace android {
namespace bpf {
// BPF loader implementation. Loads an eBPF ELF object
int loadProg(const char* elfpath);
// PICO: loads an eBPF ELF object without reusing pinned maps/programs (stale pins are unlinked
// and recreated) and appends every pin path to unlinkList so the caller can remove them later.
int loadProgWithUnlink(const char* elfpath, std::vector<std::string>& unlinkList);
}  // namespace bpf
}  // namespace android

#endif
