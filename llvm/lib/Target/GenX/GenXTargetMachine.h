/*
 * Copyright (c) 2018, Intel Corporation
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included
 * in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR
 * OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 */

//===----------------------------------------------------------------------===//
//
// This file declares the TargetMachine that is used by the GenX backend.
//
// Unlike a normal CPU backend, the GenX backend does not use CodeGen (the
// LLVM target independent code generator).
//
//===----------------------------------------------------------------------===//

#ifndef GENXTARGETMACHINE_H
#define GENXTARGETMACHINE_H

#include "GenXSubtarget.h"
#include "llvm/IR/DataLayout.h"
#include "llvm/Target/TargetMachine.h"

namespace llvm {

class formatted_raw_ostream;

class GenXTargetMachine : public TargetMachine {
  const DataLayout DL;
  GenXSubtarget    Subtarget;

public:
  GenXTargetMachine(const Target &T, StringRef TT,
                    StringRef CPU, StringRef FS, const TargetOptions &Options,
                    Reloc::Model RM, CodeModel::Model CM,
                    CodeGenOpt::Level OL);

  virtual bool addPassesToEmitFile(PassManagerBase &PM,
                                   formatted_raw_ostream &Out,
                                   CodeGenFileType FileType,
                                   bool DisableVerify,
                                   AnalysisID StartAfter,
                                   AnalysisID StopAfter);

  virtual const DataLayout *getDataLayout() const { return &DL; }
};

extern Target TheGenXTarget;

} // End llvm namespace

#endif
