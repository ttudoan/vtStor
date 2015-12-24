/*
<License>
Copyright 2015 Virtium Technology

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

http ://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
</License>
*/

#ifndef __vtStorProtocolAtaPassthroughManaged_h__
#define __vtStorProtocolAtaPassthroughManaged_h__
#pragma once

#include "IProtocol.h"
#include "SharedPtrManaged.h"

namespace vtStor
{
    namespace Protocol
    {
        namespace Managed
        {
            public ref class cProtocolAtaPassThrough : public vtStor::Managed::cProtocolInterface
            {
            public:
                cProtocolAtaPassThrough(vtStor::Managed::IRunTimeDll^ RunTimeDll);
                virtual ~cProtocolAtaPassThrough();

            protected:
                !cProtocolAtaPassThrough();

            public:
                virtual operator void*() override;

            private:
                vtStor::Managed::cSharedPtr<vtStor::IProtocol> m_Protocol;
            };
        }
    }
}

#endif