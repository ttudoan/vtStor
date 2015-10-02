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
#include "StorageUtility.h"

#include "vtStorScsi.h"
#include "DriveScsi.h"
#include "ProtocolScsiPassThrough.h"

#include "DriveEnumeratorScsi.h"

namespace vtStor
{ 
cDriveEnumeratorScsi::~cDriveEnumeratorScsi()
{

}

std::shared_ptr<cDriveInterface> cDriveEnumeratorScsi::EnumerateDrive(const std::shared_ptr<cDeviceInterface>& Device)
{
    DeviceHandle deviceHandle;
    eErrorCode errorCode;

    try
    {
        deviceHandle = Device->Handle();
    }
    catch (std::exception ex)
    {
        //fprintf(stderr, "\nEnumerateDrive was not successful. Exception:%s.", ex.what());
        //TODO: handle error
        return(nullptr);
    }

    sStorageAdapterProperty storageAdapterProperty;
    errorCode = GetStorageAdapterProperty(deviceHandle, storageAdapterProperty);

    if (eErrorCode::None != errorCode)
    {
        //TODO: handle error
        return(nullptr);
    }

    if (true == IsScsiDeviceBus(storageAdapterProperty))
    {
        std::shared_ptr<cDriveInterface> drive = std::make_shared<cDriveScsi>(Device, deviceHandle);

        return(drive);
    }

    return(nullptr);
}

}