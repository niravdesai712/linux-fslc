/****************************************************************************
*
*    Copyright (C) 2005 - 2014 by Vivante Corp.
*
*    This program is free software; you can redistribute it and/or modify
*    it under the terms of the GNU General Public License as published by
*    the Free Software Foundation; either version 2 of the license, or
*    (at your option) any later version.
*
*    This program is distributed in the hope that it will be useful,
*    but WITHOUT ANY WARRANTY; without even the implied warranty of
*    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
*    GNU General Public License for more details.
*
*    You should have received a copy of the GNU General Public License
*    along with this program; if not write to the Free Software
*    Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
*
*****************************************************************************/


#include <linux/utsname.h>
#include "gc_hal_kernel_precomp.h"

#define _GC_OBJ_ZONE    gcvZONE_KERNEL

/*******************************************************************************
***** Version Signature *******************************************************/

#define _gcmTXT2STR(t) #t
#define gcmTXT2STR(t) _gcmTXT2STR(t)
const char * _VERSION = "\n\0$VERSION$"
                        gcmTXT2STR(gcvVERSION_MAJOR) "."
                        gcmTXT2STR(gcvVERSION_MINOR) "."
                        gcmTXT2STR(gcvVERSION_PATCH) ":"
                        gcmTXT2STR(gcvVERSION_BUILD) "$\n";

/******************************************************************************\
******************************* gckKERNEL API Code ******************************
\******************************************************************************/

#if gcmIS_DEBUG(gcdDEBUG_TRACE)
#define gcmDEFINE2TEXT(d) #d
gctCONST_STRING _DispatchText[] =
{
    gcmDEFINE2TEXT(gcvHAL_QUERY_VIDEO_MEMORY),
    gcmDEFINE2TEXT(gcvHAL_QUERY_CHIP_IDENTITY),
    gcmDEFINE2TEXT(gcvHAL_ALLOCATE_NON_PAGED_MEMORY),
    gcmDEFINE2TEXT(gcvHAL_FREE_NON_PAGED_MEMORY),
    gcmDEFINE2TEXT(gcvHAL_ALLOCATE_CONTIGUOUS_MEMORY),
    gcmDEFINE2TEXT(gcvHAL_FREE_CONTIGUOUS_MEMORY),
    gcmDEFINE2TEXT(gcvHAL_ALLOCATE_VIDEO_MEMORY),
    gcmDEFINE2TEXT(gcvHAL_ALLOCATE_LINEAR_VIDEO_MEMORY),
    gcmDEFINE2TEXT(gcvHAL_RELEASE_VIDEO_MEMORY),
    gcmDEFINE2TEXT(gcvHAL_MAP_MEMORY),
    gcmDEFINE2TEXT(gcvHAL_UNMAP_MEMORY),
    gcmDEFINE2TEXT(gcvHAL_MAP_USER_MEMORY),
    gcmDEFINE2TEXT(gcvHAL_UNMAP_USER_MEMORY),
    gcmDEFINE2TEXT(gcvHAL_LOCK_VIDEO_MEMORY),
    gcmDEFINE2TEXT(gcvHAL_UNLOCK_VIDEO_MEMORY),
    gcmDEFINE2TEXT(gcvHAL_EVENT_COMMIT),
    gcmDEFINE2TEXT(gcvHAL_USER_SIGNAL),
    gcmDEFINE2TEXT(gcvHAL_SIGNAL),
    gcmDEFINE2TEXT(gcvHAL_WRITE_DATA),
    gcmDEFINE2TEXT(gcvHAL_COMMIT),
    gcmDEFINE2TEXT(gcvHAL_STALL),
    gcmDEFINE2TEXT(gcvHAL_READ_REGISTER),
    gcmDEFINE2TEXT(gcvHAL_WRITE_REGISTER),
    gcmDEFINE2TEXT(gcvHAL_GET_PROFILE_SETTING),
    gcmDEFINE2TEXT(gcvHAL_SET_PROFILE_SETTING),
    gcmDEFINE2TEXT(gcvHAL_READ_ALL_PROFILE_REGISTERS),
    gcmDEFINE2TEXT(gcvHAL_PROFILE_REGISTERS_2D),
#if VIVANTE_PROFILER_PERDRAW
    gcvHAL_READ_PROFILER_REGISTER_SETTING,
#endif
    gcmDEFINE2TEXT(gcvHAL_SET_POWER_MANAGEMENT_STATE),
    gcmDEFINE2TEXT(gcvHAL_QUERY_POWER_MANAGEMENT_STATE),
    gcmDEFINE2TEXT(gcvHAL_GET_BASE_ADDRESS),
    gcmDEFINE2TEXT(gcvHAL_SET_IDLE),
    gcmDEFINE2TEXT(gcvHAL_QUERY_KERNEL_SETTINGS),
    gcmDEFINE2TEXT(gcvHAL_RESET),
    gcmDEFINE2TEXT(gcvHAL_MAP_PHYSICAL),
    gcmDEFINE2TEXT(gcvHAL_DEBUG),
    gcmDEFINE2TEXT(gcvHAL_CACHE),
    gcmDEFINE2TEXT(gcvHAL_TIMESTAMP),
    gcmDEFINE2TEXT(gcvHAL_DATABASE),
    gcmDEFINE2TEXT(gcvHAL_VERSION),
    gcmDEFINE2TEXT(gcvHAL_CHIP_INFO),
    gcmDEFINE2TEXT(gcvHAL_ATTACH),
    gcmDEFINE2TEXT(gcvHAL_DETACH),
    gcmDEFINE2TEXT(gcvHAL_COMPOSE),
    gcmDEFINE2TEXT(gcvHAL_SET_TIMEOUT),
    gcmDEFINE2TEXT(gcvHAL_GET_FRAME_INFO),
    gcmDEFINE2TEXT(gcvHAL_QUERY_COMMAND_BUFFER),
    gcmDEFINE2TEXT(gcvHAL_COMMIT_DONE),
    gcmDEFINE2TEXT(gcvHAL_DUMP_GPU_STATE),
    gcmDEFINE2TEXT(gcvHAL_DUMP_EVENT),
    gcmDEFINE2TEXT(gcvHAL_ALLOCATE_VIRTUAL_COMMAND_BUFFER),
    gcmDEFINE2TEXT(gcvHAL_FREE_VIRTUAL_COMMAND_BUFFER),
    gcmDEFINE2TEXT(gcvHAL_SET_FSCALE_VALUE),
    gcmDEFINE2TEXT(gcvHAL_GET_FSCALE_VALUE),
    gcmDEFINE2TEXT(gcvHAL_NAME_VIDEO_MEMORY),
    gcmDEFINE2TEXT(gcvHAL_IMPORT_VIDEO_MEMORY),
    gcmDEFINE2TEXT(gcvHAL_QUERY_RESET_TIME_STAMP),
    gcmDEFINE2TEXT(gcvHAL_READ_REGISTER_EX),
    gcmDEFINE2TEXT(gcvHAL_WRITE_REGISTER_EX),
    gcmDEFINE2TEXT(gcvHAL_SYNC_POINT),
    gcmDEFINE2TEXT(gcvHAL_CREATE_NATIVE_FENCE),
    gcmDEFINE2TEXT(gcvHAL_DESTROY_MMU),
    gcmDEFINE2TEXT(gcvHAL_SHBUF),
};
#endif

#if gcdGPU_TIMEOUT && gcdINTERRUPT_STATISTIC
void
_MonitorTimerFunction(
    gctPOINTER Data
    )
{
    gckKERNEL kernel = (gckKERNEL)Data;
    gctUINT32 pendingInterrupt;
    gctBOOL reset = gcvFALSE;
    gctUINT32 mask;
    gctUINT32 advance = kernel->timeOut/2;

#if gcdENABLE_VG
    if (kernel->core == gcvCORE_VG)
    {
        return;
    }
#endif

    if (kernel->monitorTimerStop)
    {
        /* Stop. */
        return;
    }

    gckOS_AtomGet(kernel->os, kernel->eventObj->interruptCount, &pendingInterrupt);

    if (kernel->monitoring == gcvFALSE)
    {
        if (pendingInterrupt)
        {
            /* Begin to mointor GPU state. */
            kernel->monitoring = gcvTRUE;

            /* Record current state. */
            kernel->lastCommitStamp = kernel->eventObj->lastCommitStamp;
            kernel->restoreAddress  = kernel->hardware->lastWaitLink;
            gcmkVERIFY_OK(gckOS_AtomGet(
                kernel->os,
                kernel->hardware->pendingEvent,
                &kernel->restoreMask
                ));

            /* Clear timeout. */
            kernel->timer = 0;
        }
    }
    else
    {
        if (pendingInterrupt)
        {
            gcmkVERIFY_OK(gckOS_AtomGet(
                kernel->os,
                kernel->hardware->pendingEvent,
                &mask
                ));

            if (kernel->eventObj->lastCommitStamp == kernel->lastCommitStamp
             && kernel->hardware->lastWaitLink    == kernel->restoreAddress
             && mask                              == kernel->restoreMask
            )
            {
                /* GPU state is not changed, accumlate timeout. */
                kernel->timer += advance;

                if (kernel->timer >= kernel->timeOut)
                {
                    /* GPU stuck, trigger reset. */
                    reset = gcvTRUE;
                }
            }
            else
            {
                /* GPU state changed, cancel current timeout.*/
                kernel->monitoring = gcvFALSE;
            }
        }
        else
        {
            /* GPU finish all jobs, cancel current timeout*/
            kernel->monitoring = gcvFALSE;
        }
    }

    if (reset)
    {
        gckKERNEL_Recovery(kernel);

        /* Work in this timeout is done. */
        kernel->monitoring = gcvFALSE;
    }

    gcmkVERIFY_OK(gckOS_StartTimer(kernel->os, kernel->monitorTimer, advance));
}
#endif

#if gcdPROCESS_ADDRESS_SPACE
gceSTATUS
_MapCommandBuffer(
    IN gckKERNEL Kernel
    )
{
    gceSTATUS status;
    gctUINT32 i;
    gctUINT32 physical;
    gckMMU mmu;

    gcmkONERROR(gckKERNEL_GetProcessMMU(Kernel, &mmu));

    for (i = 0; i < gcdCOMMAND_QUEUES; i++)
    {
        gcmkONERROR(gckOS_GetPhysicalAddress(
            Kernel->os,
            Kernel->command->queues[i].logical,
            &physical
            ));

        gcmkONERROR(gckMMU_FlatMapping(mmu, physical));
    }

    return gcvSTATUS_OK;

OnError:
    return status;
}
#endif

void
_DumpDriverConfigure(
    IN gckKERNEL Kernel
    )
{
    gcmkPRINT_N(0, "**************************\n");
    gcmkPRINT_N(0, "***   GPU DRV CONFIG   ***\n");
    gcmkPRINT_N(0, "**************************\n");

    gcmkPRINT("Galcore version %d.%d.%d.%d\n",
              gcvVERSION_MAJOR, gcvVERSION_MINOR, gcvVERSION_PATCH, gcvVERSION_BUILD);

    gckOS_DumpParam();
}

void
_DumpState(
    IN gckKERNEL Kernel
    )
{
    /* Dump GPU Debug registers. */
    gcmkVERIFY_OK(gckHARDWARE_DumpGPUState(Kernel->hardware));

    if (Kernel->virtualCommandBuffer)
    {
        gcmkVERIFY_OK(gckCOMMAND_DumpExecutingBuffer(Kernel->command));
    }

    /* Dump Pending event. */
    gcmkVERIFY_OK(gckEVENT_Dump(Kernel->eventObj));

    /* Dump Process DB. */
    gcmkVERIFY_OK(gckKERNEL_DumpProcessDB(Kernel));

#if gcdRECORD_COMMAND
    /* Dump record. */
    gckRECORDER_Dump(Kernel->command->recorder);
#endif
}

/*******************************************************************************
**
**  gckKERNEL_Construct
**
**  Construct a new gckKERNEL object.
**
**  INPUT:
**
**      gckOS Os
**          Pointer to an gckOS object.
**
**      gceCORE Core
**          Specified core.
**
**      IN gctPOINTER Context
**          Pointer to a driver defined context.
**
**      IN gckDB SharedDB,
**          Pointer to a shared DB.
**
**  OUTPUT:
**
**      gckKERNEL * Kernel
**          Pointer to a variable that will hold the pointer to the gckKERNEL
**          object.
*/

gceSTATUS
gckKERNEL_Construct(
    IN gckOS Os,
    IN gceCORE Core,
    IN gctPOINTER Context,
    IN gckDB SharedDB,
    OUT gckKERNEL * Kernel
    )
{
    gckKERNEL kernel = gcvNULL;
    gceSTATUS status;
    gctSIZE_T i;
    gctPOINTER pointer = gcvNULL;

    gcmkHEADER_ARG("Os=0x%x Context=0x%x", Os, Context);

    /* Verify the arguments. */
    gcmkVERIFY_OBJECT(Os, gcvOBJ_OS);
    gcmkVERIFY_ARGUMENT(Kernel != gcvNULL);

    /* Allocate the gckKERNEL object. */
    gcmkONERROR(gckOS_Allocate(Os,
                               gcmSIZEOF(struct _gckKERNEL),
                               &pointer));

    kernel = pointer;

    /* Zero the object pointers. */
    kernel->hardware     = gcvNULL;
    kernel->command      = gcvNULL;
    kernel->eventObj     = gcvNULL;
    kernel->mmu          = gcvNULL;
#if gcdDVFS
    kernel->dvfs         = gcvNULL;
#endif
    kernel->monitorTimer = gcvNULL;

    /* Initialize the gckKERNEL object. */
    kernel->object.type = gcvOBJ_KERNEL;
    kernel->os          = Os;
    kernel->core        = Core;

    if (SharedDB == gcvNULL)
    {
        gcmkONERROR(gckOS_Allocate(Os,
                                   gcmSIZEOF(struct _gckDB),
                                   &pointer));

        kernel->db               = pointer;
        kernel->dbCreated        = gcvTRUE;
        kernel->db->freeDatabase = gcvNULL;
        kernel->db->freeRecord   = gcvNULL;
        kernel->db->dbMutex      = gcvNULL;
        kernel->db->lastDatabase = gcvNULL;
        kernel->db->idleTime     = 0;
        kernel->db->lastIdle     = 0;
        kernel->db->lastSlowdown = 0;

        for (i = 0; i < gcmCOUNTOF(kernel->db->db); ++i)
        {
            kernel->db->db[i] = gcvNULL;
        }

        /* Construct a database mutex. */
        gcmkONERROR(gckOS_CreateMutex(Os, &kernel->db->dbMutex));

        /* Construct a video memory name database. */
        gcmkONERROR(gckKERNEL_CreateIntegerDatabase(kernel, &kernel->db->nameDatabase));

        /* Construct a video memory name database mutex. */
        gcmkONERROR(gckOS_CreateMutex(Os, &kernel->db->nameDatabaseMutex));

        /* Construct a pointer name database. */
        gcmkONERROR(gckKERNEL_CreateIntegerDatabase(kernel, &kernel->db->pointerDatabase));

        /* Construct a pointer name database mutex. */
        gcmkONERROR(gckOS_CreateMutex(Os, &kernel->db->pointerDatabaseMutex));
    }
    else
    {
        kernel->db               = SharedDB;
        kernel->dbCreated        = gcvFALSE;
    }

    for (i = 0; i < gcmCOUNTOF(kernel->timers); ++i)
    {
        kernel->timers[i].startTime = 0;
        kernel->timers[i].stopTime = 0;
    }

    /* Save context. */
    kernel->context = Context;

    /* Construct atom holding number of clients. */
    kernel->atomClients = gcvNULL;
    gcmkONERROR(gckOS_AtomConstruct(Os, &kernel->atomClients));

#if gcdENABLE_VG
    kernel->vg = gcvNULL;

    if (Core == gcvCORE_VG)
    {
        /* Construct the gckMMU object. */
        gcmkONERROR(
            gckVGKERNEL_Construct(Os, Context, kernel, &kernel->vg));

        kernel->timeOut = gcdGPU_TIMEOUT;
    }
    else
#endif
    {
        /* Construct the gckHARDWARE object. */
        gcmkONERROR(
            gckHARDWARE_Construct(Os, kernel->core, &kernel->hardware));

        /* Set pointer to gckKERNEL object in gckHARDWARE object. */
        kernel->hardware->kernel = kernel;

        kernel->timeOut = kernel->hardware->type == gcvHARDWARE_2D
                        ? gcdGPU_2D_TIMEOUT
                        : gcdGPU_TIMEOUT
                        ;

        /* Initialize virtual command buffer. */
        kernel->virtualCommandBuffer = gcvTRUE;

        /* Construct the gckCOMMAND object. */
        gcmkONERROR(
            gckCOMMAND_Construct(kernel, &kernel->command));

        /* Construct the gckEVENT object. */
        gcmkONERROR(
            gckEVENT_Construct(kernel, &kernel->eventObj));

        /* Construct the gckMMU object. */
        gcmkONERROR(
            gckMMU_Construct(kernel, gcdMMU_SIZE, &kernel->mmu));

        gcmkVERIFY_OK(gckOS_GetTime(&kernel->resetTimeStamp));

        gcmkONERROR(gckHARDWARE_PrepareFunctions(kernel->hardware));

        /* Initialize the hardware. */
        gcmkONERROR(
            gckHARDWARE_InitializeHardware(kernel->hardware));

#if gcdDVFS
        if (gckHARDWARE_IsFeatureAvailable(kernel->hardware,
                                           gcvFEATURE_DYNAMIC_FREQUENCY_SCALING))
        {
            gcmkONERROR(gckDVFS_Construct(kernel->hardware, &kernel->dvfs));
            gcmkONERROR(gckDVFS_Start(kernel->dvfs));
        }
#endif
    }

    spin_lock_init(&kernel->irq_lock);

#if VIVANTE_PROFILER
    /* Initialize profile setting */
    kernel->profileEnable = gcvFALSE;
    kernel->profileCleanRegister = gcvTRUE;
#endif

#if gcdANDROID_NATIVE_FENCE_SYNC
    gcmkONERROR(gckOS_CreateSyncTimeline(Os, &kernel->timeline));
#endif

    kernel->recovery      = gcvTRUE;
    kernel->stuckDump     = 1;

    kernel->virtualBufferHead =
    kernel->virtualBufferTail = gcvNULL;

    gcmkONERROR(
        gckOS_CreateMutex(Os, (gctPOINTER)&kernel->virtualBufferLock));

#if gcdGPU_TIMEOUT && gcdINTERRUPT_STATISTIC
    if (kernel->timeOut)
    {
        gcmkVERIFY_OK(gckOS_CreateTimer(
            Os,
            (gctTIMERFUNCTION)_MonitorTimerFunction,
            (gctPOINTER)kernel,
            &kernel->monitorTimer
            ));

        kernel->monitoring  = gcvFALSE;

        kernel->monitorTimerStop = gcvFALSE;

        gcmkVERIFY_OK(gckOS_StartTimer(
            Os,
            kernel->monitorTimer,
            100
            ));
    }
#endif

    /* Return pointer to the gckKERNEL object. */
    *Kernel = kernel;

    /* Success. */
    gcmkFOOTER_ARG("*Kernel=0x%x", *Kernel);
    return gcvSTATUS_OK;

OnError:
    if (kernel != gcvNULL)
    {
#if gcdENABLE_VG
        if (Core != gcvCORE_VG)
#endif
        {
            if (kernel->eventObj != gcvNULL)
            {
                gcmkVERIFY_OK(gckEVENT_Destroy(kernel->eventObj));
            }

            if (kernel->command != gcvNULL)
            {
            gcmkVERIFY_OK(gckCOMMAND_Destroy(kernel->command));
            }

            if (kernel->hardware != gcvNULL)
            {
                /* Turn off the power. */
                gcmkVERIFY_OK(gckOS_SetGPUPower(kernel->hardware->os,
                                                kernel->hardware->core,
                                                gcvFALSE,
                                                gcvFALSE));
                gcmkVERIFY_OK(gckHARDWARE_Destroy(kernel->hardware));
            }
        }

        if (kernel->atomClients != gcvNULL)
        {
            gcmkVERIFY_OK(gckOS_AtomDestroy(Os, kernel->atomClients));
        }

        if (kernel->dbCreated && kernel->db != gcvNULL)
        {
            if (kernel->db->dbMutex != gcvNULL)
            {
                /* Destroy the database mutex. */
                gcmkVERIFY_OK(gckOS_DeleteMutex(Os, kernel->db->dbMutex));
            }

            gcmkVERIFY_OK(gcmkOS_SAFE_FREE(Os, kernel->db));
        }

        if (kernel->virtualBufferLock != gcvNULL)
        {
            /* Destroy the virtual command buffer mutex. */
            gcmkVERIFY_OK(gckOS_DeleteMutex(Os, kernel->virtualBufferLock));
        }

#if gcdDVFS
        if (kernel->dvfs)
        {
            gcmkVERIFY_OK(gckDVFS_Stop(kernel->dvfs));
            gcmkVERIFY_OK(gckDVFS_Destroy(kernel->dvfs));
        }
#endif

#if gcdANDROID_NATIVE_FENCE_SYNC
        if (kernel->timeline)
        {
            gcmkVERIFY_OK(gckOS_DestroySyncTimeline(Os, kernel->timeline));
        }
#endif

        if (kernel->monitorTimer)
        {
            gcmkVERIFY_OK(gckOS_StopTimer(Os, kernel->monitorTimer));
            gcmkVERIFY_OK(gckOS_DestroyTimer(Os, kernel->monitorTimer));
        }

        gcmkVERIFY_OK(gcmkOS_SAFE_FREE(Os, kernel));
    }

    /* Return the error. */
    gcmkFOOTER();
    return status;
}

/*******************************************************************************
**
**  gckKERNEL_Destroy
**
**  Destroy an gckKERNEL object.
**
**  INPUT:
**
**      gckKERNEL Kernel
**          Pointer to an gckKERNEL object to destroy.
**
**  OUTPUT:
**
**      Nothing.
*/
gceSTATUS
gckKERNEL_Destroy(
    IN gckKERNEL Kernel
    )
{
    gctSIZE_T i;
    gcsDATABASE_PTR database, databaseNext;
    gcsDATABASE_RECORD_PTR record, recordNext;

    gcmkHEADER_ARG("Kernel=0x%x", Kernel);

    /* Verify the arguments. */
    gcmkVERIFY_OBJECT(Kernel, gcvOBJ_KERNEL);

    /* Destroy the database. */
    if (Kernel->dbCreated)
    {
        for (i = 0; i < gcmCOUNTOF(Kernel->db->db); ++i)
        {
            if (Kernel->db->db[i] != gcvNULL)
            {
                gcmkVERIFY_OK(
                    gckKERNEL_DestroyProcessDB(Kernel, Kernel->db->db[i]->processID));
            }
        }

        /* Free all databases. */
        for (database = Kernel->db->freeDatabase;
             database != gcvNULL;
             database = databaseNext)
        {
            databaseNext = database->next;

            gcmkVERIFY_OK(gckOS_DeleteMutex(Kernel->os, database->counterMutex));
            gcmkVERIFY_OK(gcmkOS_SAFE_FREE(Kernel->os, database));
        }

        if (Kernel->db->lastDatabase != gcvNULL)
        {
            gcmkVERIFY_OK(gckOS_DeleteMutex(Kernel->os, Kernel->db->lastDatabase->counterMutex));
            gcmkVERIFY_OK(gcmkOS_SAFE_FREE(Kernel->os, Kernel->db->lastDatabase));
        }

        /* Free all database records. */
        for (record = Kernel->db->freeRecord; record != gcvNULL; record = recordNext)
        {
            recordNext = record->next;
            gcmkVERIFY_OK(gcmkOS_SAFE_FREE(Kernel->os, record));
        }

        /* Destroy the database mutex. */
        gcmkVERIFY_OK(gckOS_DeleteMutex(Kernel->os, Kernel->db->dbMutex));

        /* Destroy video memory name database. */
        gcmkVERIFY_OK(gckKERNEL_DestroyIntegerDatabase(Kernel, Kernel->db->nameDatabase));

        /* Destroy video memory name database mutex. */
        gcmkVERIFY_OK(gckOS_DeleteMutex(Kernel->os, Kernel->db->nameDatabaseMutex));


        /* Destroy id-pointer database. */
        gcmkVERIFY_OK(gckKERNEL_DestroyIntegerDatabase(Kernel, Kernel->db->pointerDatabase));

        /* Destroy id-pointer database mutex. */
        gcmkVERIFY_OK(gckOS_DeleteMutex(Kernel->os, Kernel->db->pointerDatabaseMutex));

        /* Destroy the database. */
        gcmkVERIFY_OK(gcmkOS_SAFE_FREE(Kernel->os, Kernel->db));

        /* Notify stuck timer to quit. */
        Kernel->monitorTimerStop = gcvTRUE;
    }

#if gcdENABLE_VG
    if (Kernel->vg)
    {
        gcmkVERIFY_OK(gckVGKERNEL_Destroy(Kernel->vg));
    }
    else
#endif
    {
        /* Destroy the gckMMU object. */
        gcmkVERIFY_OK(gckMMU_Destroy(Kernel->mmu));

        /* Destroy the gckCOMMNAND object. */
        gcmkVERIFY_OK(gckCOMMAND_Destroy(Kernel->command));

        /* Destroy the gckEVENT object. */
        gcmkVERIFY_OK(gckEVENT_Destroy(Kernel->eventObj));

        /* Destroy the gckHARDWARE object. */
        gcmkVERIFY_OK(gckHARDWARE_Destroy(Kernel->hardware));
    }

    /* Detsroy the client atom. */
    gcmkVERIFY_OK(gckOS_AtomDestroy(Kernel->os, Kernel->atomClients));

    gcmkVERIFY_OK(gckOS_DeleteMutex(Kernel->os, Kernel->virtualBufferLock));

#if gcdDVFS
    if (Kernel->dvfs)
    {
        gcmkVERIFY_OK(gckDVFS_Stop(Kernel->dvfs));
        gcmkVERIFY_OK(gckDVFS_Destroy(Kernel->dvfs));
    }
#endif

#if gcdANDROID_NATIVE_FENCE_SYNC
    gcmkVERIFY_OK(gckOS_DestroySyncTimeline(Kernel->os, Kernel->timeline));
#endif

    if (Kernel->monitorTimer)
    {
        gcmkVERIFY_OK(gckOS_StopTimer(Kernel->os, Kernel->monitorTimer));
        gcmkVERIFY_OK(gckOS_DestroyTimer(Kernel->os, Kernel->monitorTimer));
    }

    /* Mark the gckKERNEL object as unknown. */
    Kernel->object.type = gcvOBJ_UNKNOWN;

    /* Free the gckKERNEL object. */
    gcmkVERIFY_OK(gcmkOS_SAFE_FREE(Kernel->os, Kernel));

    /* Success. */
    gcmkFOOTER_NO();
    return gcvSTATUS_OK;
}

/*******************************************************************************
**
**  _AllocateMemory
**
**  Private function to walk all required memory pools to allocate the requested
**  amount of video memory.
**
**  INPUT:
**
**      gckKERNEL Kernel
**          Pointer to an gckKERNEL object.
**
**      gcsHAL_INTERFACE * Interface
**          Pointer to a gcsHAL_INTERFACE structure that defines the command to
**          be dispatched.
**
**  OUTPUT:
**
**      gcsHAL_INTERFACE * Interface
**          Pointer to a gcsHAL_INTERFACE structure that receives any data to be
**          returned.
*/
gceSTATUS
gckKERNEL_AllocateLinearMemory(
    IN gckKERNEL Kernel,
    IN gctUINT32 ProcessID,
    IN OUT gcePOOL * Pool,
    IN gctSIZE_T Bytes,
    IN gctUINT32 Alignment,
    IN gceSURF_TYPE Type,
    IN gctUINT32 Flag,
    OUT gctUINT32 * Node
    )
{
    gcePOOL pool;
    gceSTATUS status;
    gckVIDMEM videoMemory;
    gctINT loopCount;
    gcuVIDMEM_NODE_PTR node = gcvNULL;
    gctBOOL tileStatusInVirtual;
    gctBOOL contiguous = gcvFALSE;
    gctBOOL cacheable = gcvFALSE;
    gctSIZE_T bytes = Bytes;
    gctUINT32 handle = 0;
    gceDATABASE_TYPE type;

    gcmkHEADER_ARG("Kernel=0x%x *Pool=%d Bytes=%lu Alignment=%lu Type=%d",
                   Kernel, *Pool, Bytes, Alignment, Type);

    gcmkVERIFY_ARGUMENT(Pool != gcvNULL);
    gcmkVERIFY_ARGUMENT(Bytes != 0);

     /* Get basic type. */
     Type &= 0xFF;

    /* Check flags. */
    contiguous = Flag & gcvALLOC_FLAG_CONTIGUOUS;
    cacheable  = Flag & gcvALLOC_FLAG_CACHEABLE;

AllocateMemory:

    /* Get initial pool. */
    switch (pool = *Pool)
    {
    case gcvPOOL_DEFAULT:
    case gcvPOOL_LOCAL:
        pool      = gcvPOOL_LOCAL_INTERNAL;
        loopCount = (gctINT) gcvPOOL_NUMBER_OF_POOLS;
        break;

    case gcvPOOL_UNIFIED:
        pool      = gcvPOOL_SYSTEM;
        loopCount = (gctINT) gcvPOOL_NUMBER_OF_POOLS;
        break;

    case gcvPOOL_CONTIGUOUS:
        loopCount = (gctINT) gcvPOOL_NUMBER_OF_POOLS;
        break;

    default:
        loopCount = 1;
        break;
    }

    while (loopCount-- > 0)
    {
        if (pool == gcvPOOL_VIRTUAL)
        {
            /* Create a gcuVIDMEM_NODE for virtual memory. */
            gcmkONERROR(
                gckVIDMEM_ConstructVirtual(Kernel, Flag | gcvALLOC_FLAG_NON_CONTIGUOUS, Bytes, &node));

            bytes = node->Virtual.bytes;
            node->Virtual.type = Type;

            /* Success. */
            break;
        }

        else
        if (pool == gcvPOOL_CONTIGUOUS)
        {
#if gcdCONTIGUOUS_SIZE_LIMIT
            if (Bytes > gcdCONTIGUOUS_SIZE_LIMIT && contiguous == gcvFALSE)
            {
                status = gcvSTATUS_OUT_OF_MEMORY;
            }
            else
#endif
            {
                /* Create a gcuVIDMEM_NODE from contiguous memory. */
                status = gckVIDMEM_ConstructVirtual(
                            Kernel,
                            Flag | gcvALLOC_FLAG_CONTIGUOUS,
                            Bytes,
                            &node);
            }

            if (gcmIS_SUCCESS(status))
            {
                bytes = node->Virtual.bytes;
                node->Virtual.type = Type;

                /* Memory allocated. */
                break;
            }
        }

        else
        /* gcvPOOL_SYSTEM can't be cacheable. */
        if (cacheable == gcvFALSE)
        {
            /* Get pointer to gckVIDMEM object for pool. */
            status = gckKERNEL_GetVideoMemoryPool(Kernel, pool, &videoMemory);

            if (gcmIS_SUCCESS(status))
            {
                /* Allocate memory. */
#if defined(gcdLINEAR_SIZE_LIMIT)
                /* 512 KB */
                if (Bytes > gcdLINEAR_SIZE_LIMIT)
                {
                    status = gcvSTATUS_OUT_OF_MEMORY;
                }
                else
#endif
                {
                    status = gckVIDMEM_AllocateLinear(Kernel,
                                                      videoMemory,
                                                      Bytes,
                                                      Alignment,
                                                      Type,
                                                      (*Pool == gcvPOOL_SYSTEM),
                                                      &node);
                }

                if (gcmIS_SUCCESS(status))
                {
                    /* Memory allocated. */
                    node->VidMem.pool = pool;
                    bytes = node->VidMem.bytes;
                    break;
                }
            }
        }

        if (pool == gcvPOOL_LOCAL_INTERNAL)
        {
            /* Advance to external memory. */
            pool = gcvPOOL_LOCAL_EXTERNAL;
        }

        else
        if (pool == gcvPOOL_LOCAL_EXTERNAL)
        {
            /* Advance to contiguous system memory. */
            pool = gcvPOOL_SYSTEM;
        }

        else
        if (pool == gcvPOOL_SYSTEM)
        {
            /* Advance to contiguous memory. */
            pool = gcvPOOL_CONTIGUOUS;
        }

        else
        if (pool == gcvPOOL_CONTIGUOUS)
        {
#if gcdENABLE_VG
            if (Kernel->vg)
            {
                tileStatusInVirtual = gcvFALSE;
            }
            else
#endif
            {
                tileStatusInVirtual =
                    gckHARDWARE_IsFeatureAvailable(Kernel->hardware,
                                                   gcvFEATURE_MC20);
            }

            if (Type == gcvSURF_TILE_STATUS && tileStatusInVirtual != gcvTRUE)
            {
                gcmkONERROR(gcvSTATUS_OUT_OF_MEMORY);
            }

            if (contiguous)
            {
                break;
            }

            /* Advance to virtual memory. */
            pool = gcvPOOL_VIRTUAL;
        }

        else
        {
            /* Out of pools. */
            gcmkONERROR(gcvSTATUS_OUT_OF_MEMORY);
        }
    }

    if (node == gcvNULL)
    {
        if (contiguous)
        {
            /* Broadcast OOM message. */
            status = gckOS_Broadcast(Kernel->os, Kernel->hardware, gcvBROADCAST_OUT_OF_MEMORY);

            if (gcmIS_SUCCESS(status))
            {
                /* Get some memory. */
                gckOS_Delay(gcvNULL, 1);
                goto AllocateMemory;
            }
        }

        /* Nothing allocated. */
        gcmkONERROR(gcvSTATUS_OUT_OF_MEMORY);
    }

    /* Allocate handle for this video memory. */
    gcmkONERROR(
        gckVIDMEM_NODE_Allocate(Kernel, node, Type, pool, &handle));

    /* Return node and pool used for allocation. */
    *Node = handle;
    *Pool = pool;

    /* Encode surface type and pool to database type. */
    type = gcvDB_VIDEO_MEMORY
         | (Type << gcdDB_VIDEO_MEMORY_TYPE_SHIFT)
         | (pool << gcdDB_VIDEO_MEMORY_POOL_SHIFT);

    /* Record in process db. */
    gcmkONERROR(
            gckKERNEL_AddProcessDB(Kernel,
                                   ProcessID,
                                   type,
                                   gcmINT2PTR(handle),
                                   gcvNULL,
                                   bytes));

    /* Return status. */
    gcmkFOOTER_ARG("*Pool=%d *Node=0x%x", *Pool, *Node);
    return gcvSTATUS_OK;

OnError:
    if (handle)
    {
        /* Destroy handle allocated. */
        gcmkVERIFY_OK(gckVIDMEM_HANDLE_Dereference(Kernel, ProcessID, handle));
    }

    if (node)
    {
        /* Free video memory allocated. */
        gcmkVERIFY_OK(gckVIDMEM_Free(Kernel, node));
    }

    /* For some case like chrome with webgl test, it needs too much memory so that it invokes oom_killer
    * And the case is killed by oom_killer, the user wants not to see the crash and hope the case iteself handles the condition
    * So the patch reports the out_of_memory to the case */
    if ( status == gcvSTATUS_OUT_OF_MEMORY && (Flag & gcvALLOC_FLAG_MEMLIMIT) )
        gcmkPRINT("The running case is out_of_memory");

    /* Return the status. */
    gcmkFOOTER();
    return status;
}

/*******************************************************************************
**
**  gckKERNEL_ReleaseVideoMemory
**
**  Release handle of a video memory.
**
**  INPUT:
**
**      gckKERNEL Kernel
**          Pointer to an gckKERNEL object.
**
**      gctUINT32 ProcessID
**          ProcessID of current process.
**
**      gctUINT32 Handle
**          Handle of video memory.
**
**  OUTPUT:
**
**          Nothing.
*/
gceSTATUS
gckKERNEL_ReleaseVideoMemory(
    IN gckKERNEL Kernel,
    IN gctUINT32 ProcessID,
    IN gctUINT32 Handle
    )
{
    gceSTATUS status;
    gckVIDMEM_NODE nodeObject;
    gceDATABASE_TYPE type;

    gcmkHEADER_ARG("Kernel=0x%08X ProcessID=%d Handle=%d",
                   Kernel, ProcessID, Handle);

    gcmkONERROR(
        gckVIDMEM_HANDLE_Lookup(Kernel, ProcessID, Handle, &nodeObject));

    type = gcvDB_VIDEO_MEMORY
         | (nodeObject->type << gcdDB_VIDEO_MEMORY_TYPE_SHIFT)
         | (nodeObject->pool << gcdDB_VIDEO_MEMORY_POOL_SHIFT);

    gcmkONERROR(
        gckKERNEL_RemoveProcessDB(Kernel,
            ProcessID,
            type,
            gcmINT2PTR(Handle)));

    gckVIDMEM_HANDLE_Dereference(Kernel, ProcessID, Handle);

    gckVIDMEM_NODE_Dereference(Kernel, nodeObject);

    gcmkFOOTER_NO();
    return gcvSTATUS_OK;

OnError:
    gcmkFOOTER();
    return status;
}

/*******************************************************************************
**
**  gckKERNEL_LockVideoMemory
**
**      Lock a video memory node. It will generate a cpu virtual address used
**      by software and a GPU address used by GPU.
**
**  INPUT:
**
**      gckKERNEL Kernel
**          Pointer to an gckKERNEL object.
**
**      gceCORE Core
**          GPU to which video memory is locked.
**
**      gcsHAL_INTERFACE * Interface
**          Pointer to a gcsHAL_INTERFACE structure that defines the command to
**          be dispatched.
**
**  OUTPUT:
**
**      gcsHAL_INTERFACE * Interface
**          Pointer to a gcsHAL_INTERFACE structure that receives any data to be
**          returned.
*/
gceSTATUS
gckKERNEL_LockVideoMemory(
    IN gckKERNEL Kernel,
    IN gceCORE Core,
    IN gctUINT32 ProcessID,
    IN gctBOOL FromUser,
    IN OUT gcsHAL_INTERFACE * Interface
    )
{
    gceSTATUS status;
    gckVIDMEM_NODE nodeObject = gcvNULL;
    gcuVIDMEM_NODE_PTR node   = gcvNULL;
    gctBOOL locked            = gcvFALSE;
    gctBOOL asynchronous      = gcvFALSE;
    gctPOINTER pointer        = gcvNULL;

    gcmkHEADER_ARG("Kernel=0x%08X ProcessID=%d",
                   Kernel, ProcessID);

    gcmkONERROR(
        gckVIDMEM_HANDLE_LookupAndReference(Kernel,
                Interface->u.LockVideoMemory.node,
                &nodeObject));

    node = nodeObject->node;

    Interface->u.LockVideoMemory.gid = 0;

    /* Lock video memory. */
    gcmkONERROR(
            gckVIDMEM_Lock(Kernel,
                nodeObject,
                Interface->u.LockVideoMemory.cacheable,
                &Interface->u.LockVideoMemory.address,
                &Interface->u.LockVideoMemory.gid,
                &Interface->u.LockVideoMemory.physicalAddress));

    locked = gcvTRUE;

    if (node->VidMem.memory->object.type == gcvOBJ_VIDMEM)
    {
        /* Map video memory address into user space. */
        gcmkONERROR(
                gckKERNEL_MapVideoMemoryEx(Kernel,
                    Core,
                    FromUser,
                    Interface->u.LockVideoMemory.address,
                    &pointer));

        Interface->u.LockVideoMemory.memory = gcmPTR_TO_UINT64(pointer);
    }
    else
    {
        Interface->u.LockVideoMemory.memory = gcmPTR_TO_UINT64(node->Virtual.logical);

        /* Success. */
        status = gcvSTATUS_OK;
    }

#if gcdPROCESS_ADDRESS_SPACE
    gcmkONERROR(gckVIDMEM_Node_Lock(
        Kernel,
        nodeObject,
        &Interface->u.LockVideoMemory.address
        ));
#endif


    gcmkONERROR(
        gckKERNEL_AddProcessDB(Kernel,
            ProcessID, gcvDB_VIDEO_MEMORY_LOCKED,
            gcmINT2PTR(Interface->u.LockVideoMemory.node),
            gcvNULL,
            0));

    gckVIDMEM_HANDLE_Reference(
        Kernel, ProcessID, (gctUINT32)Interface->u.LockVideoMemory.node);

    gcmkFOOTER_NO();
    return gcvSTATUS_OK;

OnError:
    if (locked)
    {
        /* Roll back the lock. */
        gcmkVERIFY_OK(gckVIDMEM_Unlock(Kernel,
                    nodeObject,
                    gcvSURF_TYPE_UNKNOWN,
                    &asynchronous));

        if (gcvTRUE == asynchronous)
        {
            /* Bottom Half */
            gcmkVERIFY_OK(gckVIDMEM_Unlock(Kernel,
                        nodeObject,
                        gcvSURF_TYPE_UNKNOWN,
                        gcvNULL));
        }
    }

    if (nodeObject != gcvNULL)
    {
        gckVIDMEM_NODE_Dereference(Kernel, nodeObject);
    }

    gcmkFOOTER();
    return status;
}

/*******************************************************************************
**
**  gckKERNEL_UnlockVideoMemory
**
**      Unlock a video memory node.
**
**  INPUT:
**
**      gckKERNEL Kernel
**          Pointer to an gckKERNEL object.
**
**      gctUINT32 ProcessID
**          ProcessID of current process.
**
**      gcsHAL_INTERFACE * Interface
**          Pointer to a gcsHAL_INTERFACE structure that defines the command to
**          be dispatched.
**
**  OUTPUT:
**
**      gcsHAL_INTERFACE * Interface
**          Pointer to a gcsHAL_INTERFACE structure that receives any data to be
**          returned.
*/
gceSTATUS
gckKERNEL_UnlockVideoMemory(
    IN gckKERNEL Kernel,
    IN gctUINT32 ProcessID,
    IN OUT gcsHAL_INTERFACE * Interface
    )
{
    gceSTATUS status;
    gckVIDMEM_NODE nodeObject;
    gcuVIDMEM_NODE_PTR node;

    gcmkHEADER_ARG("Kernel=0x%08X ProcessID=%d",
                   Kernel, ProcessID);

    gcmkONERROR(gckVIDMEM_HANDLE_Lookup(
        Kernel,
        ProcessID,
        (gctUINT32)Interface->u.UnlockVideoMemory.node,
        &nodeObject));

    node = nodeObject->node;

    /* Unlock video memory. */
    gcmkONERROR(gckVIDMEM_Unlock(
        Kernel,
        nodeObject,
        Interface->u.UnlockVideoMemory.type,
        &Interface->u.UnlockVideoMemory.asynchroneous));

    gcmkFOOTER_NO();
    return gcvSTATUS_OK;

OnError:
    gcmkFOOTER();
    return status;
}

gceSTATUS
gckKERNEL_QueryDatabase(
    IN gckKERNEL Kernel,
    IN gctUINT32 ProcessID,
    IN OUT gcsHAL_INTERFACE * Interface
    )
{
    gceSTATUS status;
    gctINT i;
    gcuDATABASE_INFO tmp;

    gceDATABASE_TYPE type[3] = {
        gcvDB_VIDEO_MEMORY | (gcvPOOL_SYSTEM << gcdDB_VIDEO_MEMORY_POOL_SHIFT),
        gcvDB_VIDEO_MEMORY | (gcvPOOL_CONTIGUOUS << gcdDB_VIDEO_MEMORY_POOL_SHIFT),
        gcvDB_VIDEO_MEMORY | (gcvPOOL_VIRTUAL << gcdDB_VIDEO_MEMORY_POOL_SHIFT),
    };

    gcmkHEADER();

    /* Query video memory. */
    gcmkONERROR(
        gckKERNEL_QueryProcessDB(Kernel,
                                 Interface->u.Database.processID,
                                 !Interface->u.Database.validProcessID,
                                 gcvDB_VIDEO_MEMORY,
                                 &Interface->u.Database.vidMem));

    /* Query non-paged memory. */
    gcmkONERROR(
        gckKERNEL_QueryProcessDB(Kernel,
                                 Interface->u.Database.processID,
                                 !Interface->u.Database.validProcessID,
                                 gcvDB_NON_PAGED,
                                 &Interface->u.Database.nonPaged));

    /* Query contiguous memory. */
    gcmkONERROR(
        gckKERNEL_QueryProcessDB(Kernel,
                                 Interface->u.Database.processID,
                                 !Interface->u.Database.validProcessID,
                                 gcvDB_CONTIGUOUS,
                                 &Interface->u.Database.contiguous));

    /* Query GPU idle time. */
    gcmkONERROR(
        gckKERNEL_QueryProcessDB(Kernel,
                                 Interface->u.Database.processID,
                                 !Interface->u.Database.validProcessID,
                                 gcvDB_IDLE,
                                 &Interface->u.Database.gpuIdle));
    for (i = 0; i < 3; i++)
    {
        /* Query each video memory pool. */
        gcmkONERROR(
            gckKERNEL_QueryProcessDB(Kernel,
                                     Interface->u.Database.processID,
                                     !Interface->u.Database.validProcessID,
                                     type[i],
                                     &Interface->u.Database.vidMemPool[i]));
    }

    /* Query virtual command buffer pool. */
    gcmkONERROR(
        gckKERNEL_QueryProcessDB(Kernel,
                                 Interface->u.Database.processID,
                                 !Interface->u.Database.validProcessID,
                                 gcvDB_COMMAND_BUFFER,
                                 &tmp));

    Interface->u.Database.vidMemPool[2].counters.bytes += tmp.counters.bytes;
    Interface->u.Database.vidMemPool[2].counters.maxBytes += tmp.counters.maxBytes;
    Interface->u.Database.vidMemPool[2].counters.totalBytes += tmp.counters.totalBytes;

    Interface->u.Database.vidMem.counters.bytes += tmp.counters.bytes;
    Interface->u.Database.vidMem.counters.maxBytes += tmp.counters.maxBytes;
    Interface->u.Database.vidMem.counters.totalBytes += tmp.counters.totalBytes;

#if gcmIS_DEBUG(gcdDEBUG_TRACE)
    gckKERNEL_DumpVidMemUsage(Kernel, Interface->u.Database.processID);
#endif

    gcmkFOOTER_NO();
    return gcvSTATUS_OK;

OnError:
    gcmkFOOTER();
    return status;
}

gceSTATUS
gckKERNEL_ConfigPowerManagement(
    IN gckKERNEL Kernel,
    IN OUT gcsHAL_INTERFACE * Interface
)
{
    gceSTATUS status;
    gctBOOL enable = Interface->u.ConfigPowerManagement.enable;

    gcmkHEADER();

    gcmkONERROR(gckHARDWARE_SetPowerManagement(Kernel->hardware, enable));

    if (enable == gcvTRUE)
    {
        gcmkONERROR(
            gckHARDWARE_SetPowerManagementState(Kernel->hardware, gcvPOWER_ON));
    }

    gcmkFOOTER_NO();
    return gcvSTATUS_OK;

OnError:
    gcmkFOOTER();
    return status;
}

/*******************************************************************************
**
**  gckKERNEL_Dispatch
**
**  Dispatch a command received from the user HAL layer.
**
**  INPUT:
**
**      gckKERNEL Kernel
**          Pointer to an gckKERNEL object.
**
**      gctBOOL FromUser
**          whether the call is from the user space.
**
**      gcsHAL_INTERFACE * Interface
**          Pointer to a gcsHAL_INTERFACE structure that defines the command to
**          be dispatched.
**
**  OUTPUT:
**
**      gcsHAL_INTERFACE * Interface
**          Pointer to a gcsHAL_INTERFACE structure that receives any data to be
**          returned.
*/
gceSTATUS
gckKERNEL_Dispatch(
    IN gckKERNEL Kernel,
    IN gctBOOL FromUser,
    IN OUT gcsHAL_INTERFACE * Interface
    )
{
    gceSTATUS status = gcvSTATUS_OK;
    gctPHYS_ADDR physical = gcvNULL;
    gctSIZE_T bytes;
    gctPOINTER logical = gcvNULL;
    gctPOINTER info = gcvNULL;
#if (gcdENABLE_3D || gcdENABLE_2D)
    gckCONTEXT context = gcvNULL;
#endif
    gckKERNEL kernel = Kernel;
    gctUINT32 address;
    gctUINT32 processID;
    gctUINT32 paddr = gcvINVALID_ADDRESS;
    gctSIGNAL   signal;
    gckVIRTUAL_COMMAND_BUFFER_PTR buffer;

    gckVIDMEM_NODE nodeObject;
    gctBOOL powerMutexAcquired = gcvFALSE;

    gcmkHEADER_ARG("Kernel=0x%x FromUser=%d Interface=0x%x",
                   Kernel, FromUser, Interface);

    /* Verify the arguments. */
    gcmkVERIFY_OBJECT(Kernel, gcvOBJ_KERNEL);
    gcmkVERIFY_ARGUMENT(Interface != gcvNULL);

#if gcmIS_DEBUG(gcdDEBUG_TRACE)
    gcmkTRACE_ZONE(gcvLEVEL_INFO, gcvZONE_KERNEL,
                   "Dispatching command %d (%s)",
                   Interface->command, _DispatchText[Interface->command]);
#endif

    /* Get the current process ID. */
    gcmkONERROR(gckOS_GetProcessID(&processID));

    /* Dispatch on command. */
    switch (Interface->command)
    {
    case gcvHAL_GET_BASE_ADDRESS:
        /* Get base address. */
        gcmkONERROR(
            gckOS_GetBaseAddress(Kernel->os,
                                 &Interface->u.GetBaseAddress.baseAddress));
        break;

    case gcvHAL_QUERY_VIDEO_MEMORY:
        /* Query video memory size. */
        gcmkONERROR(gckKERNEL_QueryVideoMemory(Kernel, Interface));
        break;

    case gcvHAL_QUERY_CHIP_IDENTITY:
        /* Query chip identity. */
        gcmkONERROR(
            gckHARDWARE_QueryChipIdentity(
                Kernel->hardware,
                &Interface->u.QueryChipIdentity));
        break;

    case gcvHAL_MAP_MEMORY:
        physical = gcmINT2PTR(Interface->u.MapMemory.physical);

        /* Map memory. */
        gcmkONERROR(
            gckKERNEL_MapMemory(Kernel,
                                physical,
                                (gctSIZE_T) Interface->u.MapMemory.bytes,
                                &logical));

        Interface->u.MapMemory.logical = gcmPTR_TO_UINT64(logical);

        gcmkVERIFY_OK(
            gckKERNEL_AddProcessDB(Kernel,
                                   processID, gcvDB_MAP_MEMORY,
                                   logical,
                                   physical,
                                   (gctSIZE_T) Interface->u.MapMemory.bytes));
        break;

    case gcvHAL_UNMAP_MEMORY:
        physical = gcmINT2PTR(Interface->u.UnmapMemory.physical);

        gcmkVERIFY_OK(
            gckKERNEL_RemoveProcessDB(Kernel,
                                      processID, gcvDB_MAP_MEMORY,
                                      gcmUINT64_TO_PTR(Interface->u.UnmapMemory.logical)));

        /* Unmap memory. */
        gcmkONERROR(
            gckKERNEL_UnmapMemory(Kernel,
                                  physical,
                                  (gctSIZE_T) Interface->u.UnmapMemory.bytes,
                                  gcmUINT64_TO_PTR(Interface->u.UnmapMemory.logical)));
        break;

    case gcvHAL_ALLOCATE_NON_PAGED_MEMORY:
        bytes = (gctSIZE_T) Interface->u.AllocateNonPagedMemory.bytes;

        /* Allocate non-paged memory. */
        gcmkONERROR(
            gckOS_AllocateNonPagedMemory(
                Kernel->os,
                FromUser,
                &bytes,
                &physical,
                &logical));

        Interface->u.AllocateNonPagedMemory.bytes    = bytes;
        Interface->u.AllocateNonPagedMemory.logical  = gcmPTR_TO_UINT64(logical);
        Interface->u.AllocateNonPagedMemory.physical = gcmPTR_TO_NAME(physical);

        gcmkVERIFY_OK(
            gckKERNEL_AddProcessDB(Kernel,
                                   processID, gcvDB_NON_PAGED,
                                   logical,
                                   gcmINT2PTR(Interface->u.AllocateNonPagedMemory.physical),
                                   bytes));
        break;

    case gcvHAL_ALLOCATE_VIRTUAL_COMMAND_BUFFER:
        bytes = (gctSIZE_T) Interface->u.AllocateVirtualCommandBuffer.bytes;

        gcmkONERROR(
            gckKERNEL_AllocateVirtualCommandBuffer(
                Kernel,
                FromUser,
                &bytes,
                &physical,
                &logical));

        Interface->u.AllocateVirtualCommandBuffer.bytes    = bytes;
        Interface->u.AllocateVirtualCommandBuffer.logical  = gcmPTR_TO_UINT64(logical);
        Interface->u.AllocateVirtualCommandBuffer.physical = gcmPTR_TO_NAME(physical);

        gcmkVERIFY_OK(
            gckKERNEL_AddProcessDB(Kernel,
                                   processID, gcvDB_COMMAND_BUFFER,
                                   logical,
                                   gcmINT2PTR(Interface->u.AllocateVirtualCommandBuffer.physical),
                                   bytes));
        break;

    case gcvHAL_FREE_NON_PAGED_MEMORY:
        physical = gcmNAME_TO_PTR(Interface->u.FreeNonPagedMemory.physical);

        gcmkVERIFY_OK(
            gckKERNEL_RemoveProcessDB(Kernel,
                                      processID, gcvDB_NON_PAGED,
                                      gcmUINT64_TO_PTR(Interface->u.FreeNonPagedMemory.logical)));

        /* Unmap user logical out of physical memory first. */
        gcmkONERROR(gckOS_UnmapUserLogical(Kernel->os,
                                           physical,
                                           (gctSIZE_T) Interface->u.FreeNonPagedMemory.bytes,
                                           gcmUINT64_TO_PTR(Interface->u.FreeNonPagedMemory.logical)));

        /* Free non-paged memory. */
        gcmkONERROR(
            gckOS_FreeNonPagedMemory(Kernel->os,
                                     (gctSIZE_T) Interface->u.FreeNonPagedMemory.bytes,
                                     physical,
                                     gcmUINT64_TO_PTR(Interface->u.FreeNonPagedMemory.logical)));

        gcmRELEASE_NAME(Interface->u.FreeNonPagedMemory.physical);
        break;

    case gcvHAL_ALLOCATE_CONTIGUOUS_MEMORY:
        bytes = (gctSIZE_T) Interface->u.AllocateContiguousMemory.bytes;

        /* Allocate contiguous memory. */
        gcmkONERROR(gckOS_AllocateContiguous(
            Kernel->os,
            FromUser,
            &bytes,
            &physical,
            &logical));

        Interface->u.AllocateContiguousMemory.bytes    = bytes;
        Interface->u.AllocateContiguousMemory.logical  = gcmPTR_TO_UINT64(logical);
        Interface->u.AllocateContiguousMemory.physical = gcmPTR_TO_NAME(physical);

        gcmkONERROR(gckHARDWARE_ConvertLogical(
            Kernel->hardware,
            logical,
            gcvTRUE,
            &Interface->u.AllocateContiguousMemory.address));

        gcmkVERIFY_OK(gckKERNEL_AddProcessDB(
            Kernel,
            processID, gcvDB_CONTIGUOUS,
            logical,
            gcmINT2PTR(Interface->u.AllocateContiguousMemory.physical),
            bytes));
        break;

    case gcvHAL_FREE_CONTIGUOUS_MEMORY:
        physical = gcmNAME_TO_PTR(Interface->u.FreeContiguousMemory.physical);

        gcmkVERIFY_OK(
            gckKERNEL_RemoveProcessDB(Kernel,
                                      processID, gcvDB_CONTIGUOUS,
                                      gcmUINT64_TO_PTR(Interface->u.FreeNonPagedMemory.logical)));

        /* Unmap user logical out of physical memory first. */
        gcmkONERROR(gckOS_UnmapUserLogical(Kernel->os,
                                           physical,
                                           (gctSIZE_T) Interface->u.FreeContiguousMemory.bytes,
                                           gcmUINT64_TO_PTR(Interface->u.FreeContiguousMemory.logical)));

        /* Free contiguous memory. */
        gcmkONERROR(
            gckOS_FreeContiguous(Kernel->os,
                                 physical,
                                 gcmUINT64_TO_PTR(Interface->u.FreeContiguousMemory.logical),
                                 (gctSIZE_T) Interface->u.FreeContiguousMemory.bytes));

        gcmRELEASE_NAME(Interface->u.FreeContiguousMemory.physical);
        break;

    case gcvHAL_ALLOCATE_VIDEO_MEMORY:

        gcmkONERROR(gcvSTATUS_NOT_SUPPORTED);

        break;

    case gcvHAL_ALLOCATE_LINEAR_VIDEO_MEMORY:
        /* Allocate memory. */
        gcmkONERROR(
            gckKERNEL_AllocateLinearMemory(Kernel, processID,
                            &Interface->u.AllocateLinearVideoMemory.pool,
                            Interface->u.AllocateLinearVideoMemory.bytes,
                            Interface->u.AllocateLinearVideoMemory.alignment,
                            Interface->u.AllocateLinearVideoMemory.type,
                            Interface->u.AllocateLinearVideoMemory.flag,
                            &Interface->u.AllocateLinearVideoMemory.node));
        break;

    case gcvHAL_RELEASE_VIDEO_MEMORY:
        /* Release video memory. */
        gcmkONERROR(gckKERNEL_ReleaseVideoMemory(
            Kernel, processID,
            (gctUINT32)Interface->u.ReleaseVideoMemory.node
            ));
        break;

    case gcvHAL_LOCK_VIDEO_MEMORY:
        /* Lock video memory. */
        gcmkONERROR(gckKERNEL_LockVideoMemory(Kernel, Kernel->core, processID, FromUser, Interface));
        break;

    case gcvHAL_UNLOCK_VIDEO_MEMORY:
        /* Unlock video memory. */
        gcmkONERROR(gckKERNEL_UnlockVideoMemory(Kernel, processID, Interface));
        break;

    case gcvHAL_EVENT_COMMIT:
        /* Commit an event queue. */
        gcmkONERROR(
            gckEVENT_Commit(Kernel->eventObj,
                            gcmUINT64_TO_PTR(Interface->u.Event.queue)));
        break;

    case gcvHAL_COMMIT:
        /* Commit a command and context buffer. */
        gcmkONERROR(
            gckCOMMAND_Commit(Kernel->command,
                              Interface->u.Commit.context ?
                                  gcmNAME_TO_PTR(Interface->u.Commit.context) : gcvNULL,
                              gcmUINT64_TO_PTR(Interface->u.Commit.commandBuffer),
                              gcmUINT64_TO_PTR(Interface->u.Commit.delta),
                              gcmUINT64_TO_PTR(Interface->u.Commit.queue),
                              processID));

        break;

    case gcvHAL_STALL:
        /* Stall the command queue. */
        gcmkONERROR(gckCOMMAND_Stall(Kernel->command, gcvFALSE));
        break;

    case gcvHAL_MAP_USER_MEMORY:
        /* Map user memory to DMA. */
        gcmkONERROR(
            gckOS_MapUserMemory(Kernel->os,
                                Kernel->core,
                                gcmUINT64_TO_PTR(Interface->u.MapUserMemory.memory),
                                Interface->u.MapUserMemory.physical,
                                (gctSIZE_T) Interface->u.MapUserMemory.size,
                                &info,
                                &Interface->u.MapUserMemory.address));

        Interface->u.MapUserMemory.info = gcmPTR_TO_NAME(info);

        gcmkVERIFY_OK(
            gckKERNEL_AddProcessDB(Kernel,
                                   processID, gcvDB_MAP_USER_MEMORY,
                                   gcmINT2PTR(Interface->u.MapUserMemory.info),
                                   gcmUINT64_TO_PTR(Interface->u.MapUserMemory.memory),
                                   (gctSIZE_T) Interface->u.MapUserMemory.size));
        break;

    case gcvHAL_UNMAP_USER_MEMORY:
        address = Interface->u.UnmapUserMemory.address;
        info = gcmNAME_TO_PTR(Interface->u.UnmapUserMemory.info);

        gcmkVERIFY_OK(
            gckKERNEL_RemoveProcessDB(Kernel,
                                      processID, gcvDB_MAP_USER_MEMORY,
                                      gcmINT2PTR(Interface->u.UnmapUserMemory.info)));
        /* Unmap user memory. */
        gcmkONERROR(
            gckOS_UnmapUserMemory(Kernel->os,
                                  Kernel->core,
                                  gcmUINT64_TO_PTR(Interface->u.UnmapUserMemory.memory),
                                  (gctSIZE_T) Interface->u.UnmapUserMemory.size,
                                  info,
                                  address));

        gcmRELEASE_NAME(Interface->u.UnmapUserMemory.info);
        break;

    case gcvHAL_USER_SIGNAL:
        /* Dispatch depends on the user signal subcommands. */
        switch(Interface->u.UserSignal.command)
        {
        case gcvUSER_SIGNAL_CREATE:
            /* Create a signal used in the user space. */
            gcmkONERROR(
                gckOS_CreateUserSignal(Kernel->os,
                                       Interface->u.UserSignal.manualReset,
                                       &Interface->u.UserSignal.id));

            gcmkVERIFY_OK(
                gckKERNEL_AddProcessDB(Kernel,
                                       processID, gcvDB_SIGNAL,
                                       gcmINT2PTR(Interface->u.UserSignal.id),
                                       gcvNULL,
                                       0));
            break;

        case gcvUSER_SIGNAL_DESTROY:
            gcmkVERIFY_OK(gckKERNEL_RemoveProcessDB(
                Kernel,
                processID, gcvDB_SIGNAL,
                gcmINT2PTR(Interface->u.UserSignal.id)));

            /* Destroy the signal. */
            gcmkONERROR(
                gckOS_DestroyUserSignal(Kernel->os,
                                        Interface->u.UserSignal.id));
            break;

        case gcvUSER_SIGNAL_SIGNAL:
            /* Signal the signal. */
            gcmkONERROR(
                gckOS_SignalUserSignal(Kernel->os,
                                       Interface->u.UserSignal.id,
                                       Interface->u.UserSignal.state));
            break;

        case gcvUSER_SIGNAL_WAIT:
            /* Wait on the signal. */
            status = gckOS_WaitUserSignal(Kernel->os,
                                          Interface->u.UserSignal.id,
                                          Interface->u.UserSignal.wait);

            break;

        case gcvUSER_SIGNAL_MAP:
            gcmkONERROR(
                gckOS_MapSignal(Kernel->os,
                               (gctSIGNAL)(gctUINTPTR_T)Interface->u.UserSignal.id,
                               (gctHANDLE)(gctUINTPTR_T)processID,
                               &signal));

            gcmkVERIFY_OK(
                gckKERNEL_AddProcessDB(Kernel,
                                       processID, gcvDB_SIGNAL,
                                       gcmINT2PTR(Interface->u.UserSignal.id),
                                       gcvNULL,
                                       0));
            break;

        case gcvUSER_SIGNAL_UNMAP:
            gcmkVERIFY_OK(gckKERNEL_RemoveProcessDB(
                Kernel,
                processID, gcvDB_SIGNAL,
                gcmINT2PTR(Interface->u.UserSignal.id)));

            /* Destroy the signal. */
            gcmkONERROR(
                gckOS_DestroyUserSignal(Kernel->os,
                                        Interface->u.UserSignal.id));
            break;

        default:
            /* Invalid user signal command. */
            gcmkONERROR(gcvSTATUS_INVALID_ARGUMENT);
        }
        break;

    case gcvHAL_SET_POWER_MANAGEMENT_STATE:
        /* Set the power management state. */
        gcmkONERROR(
            gckHARDWARE_SetPowerManagementState(
                Kernel->hardware,
                Interface->u.SetPowerManagement.state));
        break;

    case gcvHAL_QUERY_POWER_MANAGEMENT_STATE:
        /* Chip is not idle. */
        Interface->u.QueryPowerManagement.isIdle = gcvFALSE;

        /* Query the power management state. */
        gcmkONERROR(gckHARDWARE_QueryPowerManagementState(
            Kernel->hardware,
            &Interface->u.QueryPowerManagement.state));

        /* Query the idle state. */
        gcmkONERROR(
            gckHARDWARE_QueryIdle(Kernel->hardware,
                                  &Interface->u.QueryPowerManagement.isIdle));
        break;

    case gcvHAL_READ_REGISTER:
#if gcdREGISTER_ACCESS_FROM_USER
        {
            gceCHIPPOWERSTATE power;

            gcmkONERROR(gckOS_AcquireMutex(Kernel->os, Kernel->hardware->powerMutex, gcvINFINITE));
            powerMutexAcquired = gcvTRUE;
            gcmkONERROR(gckHARDWARE_QueryPowerManagementState(Kernel->hardware,
                                                              &power));
            if (power == gcvPOWER_ON)
            {
                /* Read a register. */
                gcmkONERROR(gckOS_ReadRegisterEx(
                    Kernel->os,
                    Kernel->core,
                    Interface->u.ReadRegisterData.address,
                    &Interface->u.ReadRegisterData.data));
            }
            else
            {
                /* Chip is in power-state. */
                Interface->u.ReadRegisterData.data = 0;
                status = gcvSTATUS_CHIP_NOT_READY;
            }
            gcmkONERROR(gckOS_ReleaseMutex(Kernel->os, Kernel->hardware->powerMutex));
            powerMutexAcquired = gcvFALSE;
        }
#else
        /* No access from user land to read registers. */
        Interface->u.ReadRegisterData.data = 0;
        status = gcvSTATUS_NOT_SUPPORTED;
#endif
        break;

    case gcvHAL_WRITE_REGISTER:
#if gcdREGISTER_ACCESS_FROM_USER
        {
            gceCHIPPOWERSTATE power;

            gcmkONERROR(gckOS_AcquireMutex(Kernel->os, Kernel->hardware->powerMutex, gcvINFINITE));
            powerMutexAcquired = gcvTRUE;
            gcmkONERROR(gckHARDWARE_QueryPowerManagementState(Kernel->hardware,
                                                                  &power));
            if (power == gcvPOWER_ON)
            {
                /* Write a register. */
                gcmkONERROR(
                    gckOS_WriteRegisterEx(Kernel->os,
                                          Kernel->core,
                                          Interface->u.WriteRegisterData.address,
                                          Interface->u.WriteRegisterData.data));
            }
            else
            {
                /* Chip is in power-state. */
                Interface->u.WriteRegisterData.data = 0;
                status = gcvSTATUS_CHIP_NOT_READY;
            }
            gcmkONERROR(gckOS_ReleaseMutex(Kernel->os, Kernel->hardware->powerMutex));
            powerMutexAcquired = gcvFALSE;
        }
#else
        /* No access from user land to write registers. */
        status = gcvSTATUS_NOT_SUPPORTED;
#endif
        break;

    case gcvHAL_READ_ALL_PROFILE_REGISTERS:
#if VIVANTE_PROFILER && VIVANTE_PROFILER_CONTEXT
        /* Read profile data according to the context. */
        gcmkONERROR(
            gckHARDWARE_QueryContextProfile(
                Kernel->hardware,
                Kernel->profileCleanRegister,
                gcmNAME_TO_PTR(Interface->u.RegisterProfileData.context),
                &Interface->u.RegisterProfileData.counters));
#elif VIVANTE_PROFILER
        /* Read all 3D profile registers. */
        gcmkONERROR(
            gckHARDWARE_QueryProfileRegisters(
                Kernel->hardware,
                Kernel->profileCleanRegister,
                &Interface->u.RegisterProfileData.counters));
#else
        status = gcvSTATUS_OK;
#endif
        break;

    case gcvHAL_PROFILE_REGISTERS_2D:
#if VIVANTE_PROFILER
        /* Read all 2D profile registers. */
        gcmkONERROR(
            gckHARDWARE_ProfileEngine2D(
                Kernel->hardware,
                gcmUINT64_TO_PTR(Interface->u.RegisterProfileData2D.hwProfile2D)));
#else
        status = gcvSTATUS_OK;
#endif
        break;

    case gcvHAL_GET_PROFILE_SETTING:
#if VIVANTE_PROFILER
        /* Get profile setting */
        Interface->u.GetProfileSetting.enable = Kernel->profileEnable;
#endif

        status = gcvSTATUS_OK;
        break;

    case gcvHAL_SET_PROFILE_SETTING:
#if VIVANTE_PROFILER
        /* Set profile setting */
        if(Kernel->hardware->gpuProfiler)
        {
            Kernel->profileEnable = Interface->u.SetProfileSetting.enable;
#if VIVANTE_PROFILER_NEW
            if (Kernel->profileEnable)
                gckHARDWARE_InitProfiler(Kernel->hardware);
#endif
        }
        else
        {
            status = gcvSTATUS_NOT_SUPPORTED;
            break;
        }
#endif

        status = gcvSTATUS_OK;
        break;

#if VIVANTE_PROFILER_PERDRAW
    case gcvHAL_READ_PROFILER_REGISTER_SETTING:
    #if VIVANTE_PROFILER
        Kernel->profileCleanRegister = Interface->u.SetProfilerRegisterClear.bclear;
    #endif
        status = gcvSTATUS_OK;
        break;
#endif

    case gcvHAL_QUERY_KERNEL_SETTINGS:
        /* Get kernel settings. */
        gcmkONERROR(
            gckKERNEL_QuerySettings(Kernel,
                                    &Interface->u.QueryKernelSettings.settings));
        break;

    case gcvHAL_RESET:
        /* Reset the hardware. */
        gcmkONERROR(
            gckHARDWARE_Reset(Kernel->hardware));
        break;

    case gcvHAL_DEBUG:
        /* Set debug level and zones. */
        if (Interface->u.Debug.set)
        {
            gckOS_SetDebugLevel(Interface->u.Debug.level);
            gckOS_SetDebugZones(Interface->u.Debug.zones,
                                Interface->u.Debug.enable);
        }

        if (Interface->u.Debug.message[0] != '\0')
        {
            /* Print a message to the debugger. */
            if (Interface->u.Debug.type == gcvMESSAGE_TEXT)
            {
               gckOS_CopyPrint(Interface->u.Debug.message);
            }
            else
            {
               gckOS_DumpBuffer(Kernel->os,
                                Interface->u.Debug.message,
                                Interface->u.Debug.messageSize,
                                gceDUMP_BUFFER_FROM_USER,
                                gcvTRUE);
            }
        }
        status = gcvSTATUS_OK;
        break;

    case gcvHAL_DUMP_GPU_STATE:
        {
            gceCHIPPOWERSTATE power;

            _DumpDriverConfigure(Kernel);

            gcmkONERROR(gckHARDWARE_QueryPowerManagementState(
                Kernel->hardware,
                &power
                ));

            if (power == gcvPOWER_ON)
            {
                Interface->u.ReadRegisterData.data = 1;

                _DumpState(Kernel);
            }
            else
            {
                Interface->u.ReadRegisterData.data = 0;
                status = gcvSTATUS_CHIP_NOT_READY;

                gcmkPRINT("[galcore]: Can't dump state if GPU isn't POWER ON.");
            }
        }
        break;

    case gcvHAL_DUMP_EVENT:
        break;

    case gcvHAL_CACHE:

        logical = gcmUINT64_TO_PTR(Interface->u.Cache.logical);

        if (Interface->u.Cache.node)
        {
            gcmkONERROR(gckVIDMEM_HANDLE_Lookup(
                Kernel,
                processID,
                Interface->u.Cache.node,
                &nodeObject));

            if (nodeObject->node->VidMem.memory->object.type == gcvOBJ_VIDMEM
             || nodeObject->node->Virtual.contiguous
            )
            {
                /* If memory is contiguous, get physical address. */
                gcmkONERROR(gckOS_GetPhysicalAddress(
                    Kernel->os, logical, (gctUINT32*)&paddr));
            }
        }

        bytes = (gctSIZE_T) Interface->u.Cache.bytes;
        switch(Interface->u.Cache.operation)
        {
        case gcvCACHE_FLUSH:
            /* Clean and invalidate the cache. */
            status = gckOS_CacheFlush(Kernel->os,
                                      processID,
                                      physical,
                                      paddr,
                                      logical,
                                      bytes);
            break;
        case gcvCACHE_CLEAN:
            /* Clean the cache. */
            status = gckOS_CacheClean(Kernel->os,
                                      processID,
                                      physical,
                                      paddr,
                                      logical,
                                      bytes);
            break;
        case gcvCACHE_INVALIDATE:
            /* Invalidate the cache. */
            status = gckOS_CacheInvalidate(Kernel->os,
                                           processID,
                                           physical,
                                           paddr,
                                           logical,
                                           bytes);
            break;

        case gcvCACHE_MEMORY_BARRIER:
            status = gckOS_MemoryBarrier(Kernel->os,
                                         logical);
            break;
        default:
            status = gcvSTATUS_INVALID_ARGUMENT;
            break;
        }
        break;

    case gcvHAL_TIMESTAMP:
        /* Check for invalid timer. */
        if ((Interface->u.TimeStamp.timer >= gcmCOUNTOF(Kernel->timers))
        ||  (Interface->u.TimeStamp.request != 2))
        {
            Interface->u.TimeStamp.timeDelta = 0;
            gcmkONERROR(gcvSTATUS_INVALID_ARGUMENT);
        }

        /* Return timer results and reset timer. */
        {
            gcsTIMER_PTR timer = &(Kernel->timers[Interface->u.TimeStamp.timer]);
            gctUINT64 timeDelta = 0;

            if (timer->stopTime < timer->startTime )
            {
                Interface->u.TimeStamp.timeDelta = 0;
                gcmkONERROR(gcvSTATUS_TIMER_OVERFLOW);
            }

            timeDelta = timer->stopTime - timer->startTime;

            /* Check truncation overflow. */
            Interface->u.TimeStamp.timeDelta = (gctINT32) timeDelta;
            /*bit0~bit30 is available*/
            if (timeDelta>>31)
            {
                Interface->u.TimeStamp.timeDelta = 0;
                gcmkONERROR(gcvSTATUS_TIMER_OVERFLOW);
            }

            status = gcvSTATUS_OK;
        }
        break;

    case gcvHAL_DATABASE:
        gcmkONERROR(gckKERNEL_QueryDatabase(Kernel, processID, Interface));
        break;

    case gcvHAL_VERSION:
        Interface->u.Version.major = gcvVERSION_MAJOR;
        Interface->u.Version.minor = gcvVERSION_MINOR;
        Interface->u.Version.patch = gcvVERSION_PATCH;
        Interface->u.Version.build = gcvVERSION_BUILD;
#if gcmIS_DEBUG(gcdDEBUG_TRACE)
        gcmkTRACE_ZONE(gcvLEVEL_INFO, gcvZONE_KERNEL,
                       "KERNEL version %d.%d.%d build %u %s",
                       gcvVERSION_MAJOR, gcvVERSION_MINOR, gcvVERSION_PATCH,
                       gcvVERSION_BUILD, utsname()->version);
#endif
        break;

    case gcvHAL_CHIP_INFO:
        /* Only if not support multi-core */
        Interface->u.ChipInfo.count = 1;
        Interface->u.ChipInfo.types[0] = Kernel->hardware->type;
        break;

#if (gcdENABLE_3D || gcdENABLE_2D)
    case gcvHAL_ATTACH:
        /* Attach user process. */
        gcmkONERROR(
            gckCOMMAND_Attach(Kernel->command,
                              &context,
                              &bytes,
                              processID));

        Interface->u.Attach.stateCount = bytes;
        Interface->u.Attach.context = gcmPTR_TO_NAME(context);

        if (Interface->u.Attach.map == gcvTRUE)
        {
            gcmkVERIFY_OK(
                gckCONTEXT_MapBuffer(context,
                                     Interface->u.Attach.physicals,
                                     Interface->u.Attach.logicals,
                                     &Interface->u.Attach.bytes));
        }

        gcmkVERIFY_OK(
            gckKERNEL_AddProcessDB(Kernel,
                                   processID, gcvDB_CONTEXT,
                                   gcmINT2PTR(Interface->u.Attach.context),
                                   gcvNULL,
                                   0));
        break;
#endif

    case gcvHAL_DETACH:
        gcmkVERIFY_OK(
            gckKERNEL_RemoveProcessDB(Kernel,
                              processID, gcvDB_CONTEXT,
                              gcmINT2PTR(Interface->u.Detach.context)));

        /* Detach user process. */
        gcmkONERROR(
            gckCOMMAND_Detach(Kernel->command,
                              gcmNAME_TO_PTR(Interface->u.Detach.context)));

        gcmRELEASE_NAME(Interface->u.Detach.context);
        break;

    case gcvHAL_COMPOSE:
        Interface->u.Compose.physical = gcmPTR_TO_UINT64(gcmNAME_TO_PTR(Interface->u.Compose.physical));
        /* Start composition. */
        gcmkONERROR(
            gckEVENT_Compose(Kernel->eventObj,
                             &Interface->u.Compose));
        break;

    case gcvHAL_SET_TIMEOUT:
         /* set timeOut value from user */
         gckKERNEL_SetTimeOut(Kernel, Interface->u.SetTimeOut.timeOut);
        break;

    case gcvHAL_GET_FRAME_INFO:
        gcmkONERROR(gckHARDWARE_GetFrameInfo(
                    Kernel->hardware,
                    gcmUINT64_TO_PTR(Interface->u.GetFrameInfo.frameInfo)));
        break;

    case gcvHAL_SET_FSCALE_VALUE:
#if gcdENABLE_FSCALE_VAL_ADJUST
        status = gckHARDWARE_SetFscaleValue(Kernel->hardware,
                                            Interface->u.SetFscaleValue.value);
#else
        status = gcvSTATUS_NOT_SUPPORTED;
#endif
        break;
    case gcvHAL_GET_FSCALE_VALUE:
#if gcdENABLE_FSCALE_VAL_ADJUST
        status = gckHARDWARE_GetFscaleValue(Kernel->hardware,
                                            &Interface->u.GetFscaleValue.value,
                                            &Interface->u.GetFscaleValue.minValue,
                                            &Interface->u.GetFscaleValue.maxValue);
#else
        status = gcvSTATUS_NOT_SUPPORTED;
#endif
        break;

    case gcvHAL_NAME_VIDEO_MEMORY:
        gcmkONERROR(gckVIDMEM_NODE_Name(Kernel,
                                        Interface->u.NameVideoMemory.handle,
                                        &Interface->u.NameVideoMemory.name));
        break;

    case gcvHAL_IMPORT_VIDEO_MEMORY:
        gcmkONERROR(gckVIDMEM_NODE_Import(Kernel,
                                          Interface->u.ImportVideoMemory.name,
                                          &Interface->u.ImportVideoMemory.handle));

        gcmkONERROR(
            gckKERNEL_AddProcessDB(Kernel,
                                   processID, gcvDB_VIDEO_MEMORY,
                                   gcmINT2PTR(Interface->u.ImportVideoMemory.handle),
                                   gcvNULL,
                                   0));
        break;

    case gcvHAL_GET_VIDEO_MEMORY_FD:
        gcmkONERROR(gckVIDMEM_NODE_GetFd(
            Kernel,
            Interface->u.GetVideoMemoryFd.handle,
            &Interface->u.GetVideoMemoryFd.fd
            ));

        /* No need to add it to processDB because OS will release all fds when
        ** process quits.
        */
        break;

    case gcvHAL_QUERY_RESET_TIME_STAMP:
        Interface->u.QueryResetTimeStamp.timeStamp = Kernel->resetTimeStamp;
        break;

    case gcvHAL_FREE_VIRTUAL_COMMAND_BUFFER:
        buffer = (gckVIRTUAL_COMMAND_BUFFER_PTR)gcmNAME_TO_PTR(Interface->u.FreeVirtualCommandBuffer.physical);

        gcmkVERIFY_OK(gckKERNEL_RemoveProcessDB(
            Kernel,
            processID,
            gcvDB_COMMAND_BUFFER,
            gcmUINT64_TO_PTR(Interface->u.FreeVirtualCommandBuffer.logical)));

        gcmkONERROR(gckOS_DestroyUserVirtualMapping(
            Kernel->os,
            buffer->physical,
            (gctSIZE_T)Interface->u.FreeVirtualCommandBuffer.bytes,
            gcmUINT64_TO_PTR(Interface->u.FreeVirtualCommandBuffer.logical)));

        gcmkONERROR(gckKERNEL_DestroyVirtualCommandBuffer(
            Kernel,
            (gctSIZE_T)Interface->u.FreeVirtualCommandBuffer.bytes,
            (gctPHYS_ADDR)buffer,
            gcmUINT64_TO_PTR(Interface->u.FreeVirtualCommandBuffer.logical)));

        gcmRELEASE_NAME(Interface->u.FreeVirtualCommandBuffer.physical);
        break;

#if gcdANDROID_NATIVE_FENCE_SYNC
    case gcvHAL_SYNC_POINT:
        {
            gctSYNC_POINT syncPoint;

            switch (Interface->u.SyncPoint.command)
            {
            case gcvSYNC_POINT_CREATE:
                gcmkONERROR(gckOS_CreateSyncPoint(Kernel->os, &syncPoint));

                Interface->u.SyncPoint.syncPoint = gcmPTR_TO_UINT64(syncPoint);

                gcmkVERIFY_OK(
                    gckKERNEL_AddProcessDB(Kernel,
                                           processID, gcvDB_SYNC_POINT,
                                           syncPoint,
                                           gcvNULL,
                                           0));
                break;

            case gcvSYNC_POINT_DESTROY:
                syncPoint = gcmUINT64_TO_PTR(Interface->u.SyncPoint.syncPoint);

                gcmkVERIFY_OK(
                    gckKERNEL_RemoveProcessDB(Kernel,
                                              processID, gcvDB_SYNC_POINT,
                                              syncPoint));

                gcmkONERROR(gckOS_DestroySyncPoint(Kernel->os, syncPoint));
                break;

            default:
                gcmkONERROR(gcvSTATUS_INVALID_ARGUMENT);
                break;
            }
        }
        break;

    case gcvHAL_CREATE_NATIVE_FENCE:
        {
            gctINT fenceFD;
            gctSYNC_POINT syncPoint =
                gcmUINT64_TO_PTR(Interface->u.CreateNativeFence.syncPoint);

            gcmkONERROR(
                gckOS_CreateNativeFence(Kernel->os,
                                        Kernel->timeline,
                                        syncPoint,
                                        &fenceFD));

            Interface->u.CreateNativeFence.fenceFD = fenceFD;
        }
        break;
#endif

    case gcvHAL_SHBUF:
        {
            gctSHBUF shBuf;
            gctPOINTER uData;
            gctUINT32 bytes;

            switch (Interface->u.ShBuf.command)
            {
            case gcvSHBUF_CREATE:
                bytes = Interface->u.ShBuf.bytes;

                /* Create. */
                gcmkONERROR(gckKERNEL_CreateShBuffer(Kernel, bytes, &shBuf));

                Interface->u.ShBuf.id = gcmPTR_TO_UINT64(shBuf);

                gcmkVERIFY_OK(
                    gckKERNEL_AddProcessDB(Kernel,
                                           processID,
                                           gcvDB_SHBUF,
                                           shBuf,
                                           gcvNULL,
                                           0));
                break;

            case gcvSHBUF_DESTROY:
                shBuf = gcmUINT64_TO_PTR(Interface->u.ShBuf.id);

                /* Check db first to avoid illegal destroy in the process. */
                gcmkONERROR(
                    gckKERNEL_RemoveProcessDB(Kernel,
                                              processID,
                                              gcvDB_SHBUF,
                                              shBuf));

                gcmkONERROR(gckKERNEL_DestroyShBuffer(Kernel, shBuf));
                break;

            case gcvSHBUF_MAP:
                shBuf = gcmUINT64_TO_PTR(Interface->u.ShBuf.id);

                /* Map for current process access. */
                gcmkONERROR(gckKERNEL_MapShBuffer(Kernel, shBuf));

                gcmkVERIFY_OK(
                    gckKERNEL_AddProcessDB(Kernel,
                                           processID,
                                           gcvDB_SHBUF,
                                           shBuf,
                                           gcvNULL,
                                           0));
                break;

            case gcvSHBUF_WRITE:
                shBuf = gcmUINT64_TO_PTR(Interface->u.ShBuf.id);
                uData = gcmUINT64_TO_PTR(Interface->u.ShBuf.data);
                bytes = Interface->u.ShBuf.bytes;

                /* Write. */
                gcmkONERROR(
                    gckKERNEL_WriteShBuffer(Kernel, shBuf, uData, bytes));
                break;

            case gcvSHBUF_READ:
                shBuf = gcmUINT64_TO_PTR(Interface->u.ShBuf.id);
                uData = gcmUINT64_TO_PTR(Interface->u.ShBuf.data);
                bytes = Interface->u.ShBuf.bytes;

                /* Read. */
                gcmkONERROR(
                    gckKERNEL_ReadShBuffer(Kernel,
                                           shBuf,
                                           uData,
                                           bytes,
                                           &bytes));

                /* Return copied size. */
                Interface->u.ShBuf.bytes = bytes;
                break;

            default:
                gcmkONERROR(gcvSTATUS_INVALID_ARGUMENT);
                break;
            }
        }
        break;

    case gcvHAL_CONFIG_POWER_MANAGEMENT:
        gcmkONERROR(gckKERNEL_ConfigPowerManagement(Kernel, Interface));
        break;

    default:
        /* Invalid command. */
        gcmkONERROR(gcvSTATUS_INVALID_ARGUMENT);
    }

OnError:
    /* Save status. */
    Interface->status = status;

    if (powerMutexAcquired == gcvTRUE)
    {
        gcmkVERIFY_OK(gckOS_ReleaseMutex(Kernel->os, Kernel->hardware->powerMutex));
    }

    /* Return the status. */
    gcmkFOOTER();
    return status;
}

/*******************************************************************************
**  gckKERNEL_AttachProcess
**
**  Attach or detach a process.
**
**  INPUT:
**
**      gckKERNEL Kernel
**          Pointer to an gckKERNEL object.
**
**      gctBOOL Attach
**          gcvTRUE if a new process gets attached or gcFALSE when a process
**          gets detatched.
**
**  OUTPUT:
**
**      Nothing.
*/
gceSTATUS
gckKERNEL_AttachProcess(
    IN gckKERNEL Kernel,
    IN gctBOOL Attach
    )
{
    gceSTATUS status;
    gctUINT32 processID;

    gcmkHEADER_ARG("Kernel=0x%x Attach=%d", Kernel, Attach);

    /* Verify the arguments. */
    gcmkVERIFY_OBJECT(Kernel, gcvOBJ_KERNEL);

    /* Get current process ID. */
    gcmkONERROR(gckOS_GetProcessID(&processID));

    gcmkONERROR(gckKERNEL_AttachProcessEx(Kernel, Attach, processID));

    /* Success. */
    gcmkFOOTER_NO();
    return gcvSTATUS_OK;

OnError:
    /* Return the status. */
    gcmkFOOTER();
    return status;
}

/*******************************************************************************
**  gckKERNEL_AttachProcessEx
**
**  Attach or detach a process with the given PID. Can be paired with gckKERNEL_AttachProcess
**     provided the programmer is aware of the consequences.
**
**  INPUT:
**
**      gckKERNEL Kernel
**          Pointer to an gckKERNEL object.
**
**      gctBOOL Attach
**          gcvTRUE if a new process gets attached or gcFALSE when a process
**          gets detatched.
**
**      gctUINT32 PID
**          PID of the process to attach or detach.
**
**  OUTPUT:
**
**      Nothing.
*/
gceSTATUS
gckKERNEL_AttachProcessEx(
    IN gckKERNEL Kernel,
    IN gctBOOL Attach,
    IN gctUINT32 PID
    )
{
    gceSTATUS status;
    gctINT32 old;

    gcmkHEADER_ARG("Kernel=0x%x Attach=%d PID=%d", Kernel, Attach, PID);

    /* Verify the arguments. */
    gcmkVERIFY_OBJECT(Kernel, gcvOBJ_KERNEL);

    if (Attach)
    {
        /* Increment the number of clients attached. */
        gcmkONERROR(
            gckOS_AtomIncrement(Kernel->os, Kernel->atomClients, &old));

        if (old == 0)
        {
#if gcdENABLE_VG
            if (Kernel->vg == gcvNULL)
#endif
            {
                gcmkONERROR(gckOS_Broadcast(Kernel->os,
                                            Kernel->hardware,
                                            gcvBROADCAST_FIRST_PROCESS));
            }
        }

        if (Kernel->dbCreated)
        {
            /* Create the process database. */
            gcmkONERROR(gckKERNEL_CreateProcessDB(Kernel, PID));
        }

#if gcdPROCESS_ADDRESS_SPACE
        /* Map kernel command buffer in the process's own MMU. */
        gcmkONERROR(_MapCommandBuffer(Kernel));
#endif
    }
    else
    {
        if (Kernel->dbCreated)
        {
            /* Clean up the process database. */
            gcmkONERROR(gckKERNEL_DestroyProcessDB(Kernel, PID));

            /* Save the last know process ID. */
            Kernel->db->lastProcessID = PID;
        }

#if gcdENABLE_VG
        if (Kernel->vg == gcvNULL)
#endif
        {
            status = gckEVENT_Submit(Kernel->eventObj, gcvTRUE, gcvFALSE, gcvFALSE);

            if (status == gcvSTATUS_INTERRUPTED && Kernel->eventObj->submitTimer)
            {
                gcmkONERROR(gckOS_StartTimer(Kernel->os,
                                             Kernel->eventObj->submitTimer,
                                             1));
            }
            else
            {
                gcmkONERROR(status);
            }
        }

        /* Decrement the number of clients attached. */
        gcmkONERROR(
            gckOS_AtomDecrement(Kernel->os, Kernel->atomClients, &old));

        if (old == 1)
        {
#if gcdENABLE_VG
            if (Kernel->vg == gcvNULL)
#endif
            {
                /* Last client detached, switch to SUSPEND power state. */
                gcmkONERROR(gckOS_Broadcast(Kernel->os,
                                            Kernel->hardware,
                                            gcvBROADCAST_LAST_PROCESS));
            }

            /* Flush the debug cache. */
            gcmkDEBUGFLUSH(~0U);
        }
    }

    /* Success. */
    gcmkFOOTER_NO();
    return gcvSTATUS_OK;

OnError:
    /* Return the status. */
    gcmkFOOTER();
    return status;
}

/*******************************************************************************
**
**  gckKERNEL_Recovery
**
**  Try to recover the GPU from a fatal error.
**
**  INPUT:
**
**      gckKERNEL Kernel
**          Pointer to an gckKERNEL object.
**
**  OUTPUT:
**
**      Nothing.
*/
gceSTATUS
gckKERNEL_Recovery(
    IN gckKERNEL Kernel
    )
{
    gceSTATUS status;
    gckEVENT eventObj;
    gckHARDWARE hardware;
    gctUINT32 mask = 0;
    gckCOMMAND command;
    gckENTRYDATA data;
    gctUINT32 i = 0, count = 0;
#if gcdINTERRUPT_STATISTIC
    gctINT32 oldValue;
#endif

    gcmkHEADER_ARG("Kernel=0x%x", Kernel);

    /* Validate the arguemnts. */
    gcmkVERIFY_OBJECT(Kernel, gcvOBJ_KERNEL);

    /* Grab gckEVENT object. */
    eventObj = Kernel->eventObj;
    gcmkVERIFY_OBJECT(eventObj, gcvOBJ_EVENT);

    /* Grab gckHARDWARE object. */
    hardware = Kernel->hardware;
    gcmkVERIFY_OBJECT(hardware, gcvOBJ_HARDWARE);

    /* Grab gckCOMMAND object. */
    command = Kernel->command;
    gcmkVERIFY_OBJECT(command, gcvOBJ_COMMAND);

    if (Kernel->stuckDump == gcdSTUCK_DUMP_MINIMAL)
    {
        gcmkPRINT("[galcore]: GPU[%d] hang, automatic recovery.", Kernel->core);
    }
    else
    {
        _DumpDriverConfigure(Kernel);
        _DumpState(Kernel);
    }

    if (Kernel->recovery == gcvFALSE)
    {
        gcmkPRINT("[galcore]: Stop driver to keep scene.");

        for (;;)
        {
            gckOS_Delay(Kernel->os, 10000);
        }
    }

    /* Clear queue. */
    do
    {
        status = gckENTRYQUEUE_Dequeue(&command->queue, &data);
    }
    while (status == gcvSTATUS_OK);

    /* Issuing a soft reset for the GPU. */
    gcmkONERROR(gckHARDWARE_Reset(hardware));

    mask = Kernel->restoreMask;

    for (i = 0; i < 32; i++)
    {
        if (mask & (1 << i))
        {
            count++;
        }
    }

    /* Handle all outstanding events now. */
#if gcdSMP
    gcmkONERROR(gckOS_AtomSet(Kernel->os, eventObj->pending, mask));
#else
    eventObj->pending = mask;
#endif

#if gcdINTERRUPT_STATISTIC
    while (count--)
    {
        gcmkONERROR(gckOS_AtomDecrement(
            Kernel->os,
            eventObj->interruptCount,
            &oldValue
            ));
    }

    gckOS_AtomClearMask(Kernel->hardware->pendingEvent, mask);
#endif

    gcmkONERROR(gckEVENT_Notify(eventObj, 1));

    gcmkVERIFY_OK(gckOS_GetTime(&Kernel->resetTimeStamp));

    /* Success. */
    gcmkFOOTER_NO();
    return gcvSTATUS_OK;

OnError:
    /* Return the status. */
    gcmkFOOTER();
    return status;
}

/*******************************************************************************
**
**  gckKERNEL_OpenUserData
**
**  Get access to the user data.
**
**  INPUT:
**
**      gckKERNEL Kernel
**          Pointer to an gckKERNEL object.
**
**      gctBOOL NeedCopy
**          The flag indicating whether or not the data should be copied.
**
**      gctPOINTER StaticStorage
**          Pointer to the kernel storage where the data is to be copied if
**          NeedCopy is gcvTRUE.
**
**      gctPOINTER UserPointer
**          User pointer to the data.
**
**      gctSIZE_T Size
**          Size of the data.
**
**  OUTPUT:
**
**      gctPOINTER * KernelPointer
**          Pointer to the kernel pointer that will be pointing to the data.
*/
gceSTATUS
gckKERNEL_OpenUserData(
    IN gckKERNEL Kernel,
    IN gctBOOL NeedCopy,
    IN gctPOINTER StaticStorage,
    IN gctPOINTER UserPointer,
    IN gctSIZE_T Size,
    OUT gctPOINTER * KernelPointer
    )
{
    gceSTATUS status;

    gcmkHEADER_ARG(
        "Kernel=0x%08X NeedCopy=%d StaticStorage=0x%08X "
        "UserPointer=0x%08X Size=%lu KernelPointer=0x%08X",
        Kernel, NeedCopy, StaticStorage, UserPointer, Size, KernelPointer
        );

    /* Validate the arguemnts. */
    gcmkVERIFY_OBJECT(Kernel, gcvOBJ_KERNEL);
    gcmkVERIFY_ARGUMENT(!NeedCopy || (StaticStorage != gcvNULL));
    gcmkVERIFY_ARGUMENT(UserPointer != gcvNULL);
    gcmkVERIFY_ARGUMENT(KernelPointer != gcvNULL);
    gcmkVERIFY_ARGUMENT(Size > 0);

    if (NeedCopy)
    {
        /* Copy the user data to the static storage. */
        gcmkONERROR(gckOS_CopyFromUserData(
            Kernel->os, StaticStorage, UserPointer, Size
            ));

        /* Set the kernel pointer. */
        * KernelPointer = StaticStorage;
    }
    else
    {
        gctPOINTER pointer = gcvNULL;

        /* Map the user pointer. */
        gcmkONERROR(gckOS_MapUserPointer(
            Kernel->os, UserPointer, Size, &pointer
            ));

        /* Set the kernel pointer. */
        * KernelPointer = pointer;
    }

OnError:
    /* Return the status. */
    gcmkFOOTER();
    return status;
}

/*******************************************************************************
**
**  gckKERNEL_CloseUserData
**
**  Release resources associated with the user data connection opened by
**  gckKERNEL_OpenUserData.
**
**  INPUT:
**
**      gckKERNEL Kernel
**          Pointer to an gckKERNEL object.
**
**      gctBOOL NeedCopy
**          The flag indicating whether or not the data should be copied.
**
**      gctBOOL FlushData
**          If gcvTRUE, the data is written back to the user.
**
**      gctPOINTER UserPointer
**          User pointer to the data.
**
**      gctSIZE_T Size
**          Size of the data.
**
**  OUTPUT:
**
**      gctPOINTER * KernelPointer
**          Kernel pointer to the data.
*/
gceSTATUS
gckKERNEL_CloseUserData(
    IN gckKERNEL Kernel,
    IN gctBOOL NeedCopy,
    IN gctBOOL FlushData,
    IN gctPOINTER UserPointer,
    IN gctSIZE_T Size,
    OUT gctPOINTER * KernelPointer
    )
{
    gceSTATUS status = gcvSTATUS_OK;
    gctPOINTER pointer;

    gcmkHEADER_ARG(
        "Kernel=0x%08X NeedCopy=%d FlushData=%d "
        "UserPointer=0x%08X Size=%lu KernelPointer=0x%08X",
        Kernel, NeedCopy, FlushData, UserPointer, Size, KernelPointer
        );

    /* Validate the arguemnts. */
    gcmkVERIFY_OBJECT(Kernel, gcvOBJ_KERNEL);
    gcmkVERIFY_ARGUMENT(UserPointer != gcvNULL);
    gcmkVERIFY_ARGUMENT(KernelPointer != gcvNULL);
    gcmkVERIFY_ARGUMENT(Size > 0);

    /* Get a shortcut to the kernel pointer. */
    pointer = * KernelPointer;

    if (pointer != gcvNULL)
    {
        if (NeedCopy)
        {
            if (FlushData)
            {
                gcmkONERROR(gckOS_CopyToUserData(
                    Kernel->os, * KernelPointer, UserPointer, Size
                    ));
            }
        }
        else
        {
            /* Unmap record from kernel memory. */
            gcmkONERROR(gckOS_UnmapUserPointer(
                Kernel->os,
                UserPointer,
                Size,
                * KernelPointer
                ));
        }

        /* Reset the kernel pointer. */
        * KernelPointer = gcvNULL;
    }

OnError:
    /* Return the status. */
    gcmkFOOTER();
    return status;
}

void
gckKERNEL_SetTimeOut(
    IN gckKERNEL Kernel,
    IN gctUINT32 timeOut
    )
{
    gcmkHEADER_ARG("Kernel=0x%x timeOut=%d", Kernel, timeOut);
#if gcdGPU_TIMEOUT
    Kernel->timeOut = timeOut;
#endif
    gcmkFOOTER_NO();
}

gceSTATUS
gckKERNEL_AllocateVirtualCommandBuffer(
    IN gckKERNEL Kernel,
    IN gctBOOL InUserSpace,
    IN OUT gctSIZE_T * Bytes,
    OUT gctPHYS_ADDR * Physical,
    OUT gctPOINTER * Logical
    )
{
    gckOS os                             = Kernel->os;
    gceSTATUS status;
    gctPOINTER logical                   = gcvNULL;
    gctSIZE_T pageCount;
    gctSIZE_T bytes                      = *Bytes;
    gckVIRTUAL_COMMAND_BUFFER_PTR buffer = gcvNULL;
    gckMMU mmu;
    gctUINT32 flag = gcvALLOC_FLAG_NON_CONTIGUOUS;

    gcmkHEADER_ARG("Os=0x%X InUserSpace=%d *Bytes=%lu",
                   os, InUserSpace, gcmOPT_VALUE(Bytes));

    /* Verify the arguments. */
    gcmkVERIFY_OBJECT(os, gcvOBJ_OS);
    gcmkVERIFY_ARGUMENT(Bytes != gcvNULL);
    gcmkVERIFY_ARGUMENT(*Bytes > 0);
    gcmkVERIFY_ARGUMENT(Physical != gcvNULL);
    gcmkVERIFY_ARGUMENT(Logical != gcvNULL);

    gcmkONERROR(gckOS_Allocate(os,
                               sizeof(gckVIRTUAL_COMMAND_BUFFER),
                               (gctPOINTER)&buffer));

    gcmkONERROR(gckOS_ZeroMemory(buffer, sizeof(gckVIRTUAL_COMMAND_BUFFER)));

    buffer->bytes = bytes;

    gcmkONERROR(gckOS_AllocatePagedMemoryEx(os,
                                            flag,
                                            bytes,
                                            gcvNULL,
                                            &buffer->physical));

    if (InUserSpace)
    {
        gcmkONERROR(gckOS_CreateUserVirtualMapping(os,
                                                   buffer->physical,
                                                   bytes,
                                                   &logical,
                                                   &pageCount));

        *Logical =
        buffer->userLogical = logical;
    }
    else
    {
        gcmkONERROR(gckOS_CreateKernelVirtualMapping(os,
                                                     buffer->physical,
                                                     bytes,
                                                     &logical,
                                                     &pageCount));

        *Logical =
        buffer->kernelLogical = logical;
    }

    buffer->pageCount = pageCount;
    buffer->kernel = Kernel;

    gcmkONERROR(gckOS_GetProcessID(&buffer->pid));

#if gcdPROCESS_ADDRESS_SPACE
    gcmkONERROR(gckKERNEL_GetProcessMMU(Kernel, &mmu));
    buffer->mmu = mmu;
#else
    mmu = Kernel->mmu;
#endif

    gcmkONERROR(gckMMU_AllocatePages(mmu,
                                     pageCount,
                                     &buffer->pageTable,
                                     &buffer->gpuAddress));


    gcmkONERROR(gckOS_MapPagesEx(os,
                                 Kernel->core,
                                 buffer->physical,
                                 pageCount,
                                 buffer->gpuAddress,
                                 buffer->pageTable));

    gcmkONERROR(gckMMU_Flush(mmu, gcvSURF_INDEX));

    *Physical = buffer;

    gcmkTRACE_ZONE(gcvLEVEL_INFO, gcvZONE_KERNEL,
                   "gpuAddress = %x pageCount = %d kernelLogical = %x userLogical=%x",
                   buffer->gpuAddress, buffer->pageCount,
                   buffer->kernelLogical, buffer->userLogical);

    gcmkVERIFY_OK(gckOS_AcquireMutex(os, Kernel->virtualBufferLock, gcvINFINITE));

    if (Kernel->virtualBufferHead == gcvNULL)
    {
        Kernel->virtualBufferHead =
        Kernel->virtualBufferTail = buffer;
    }
    else
    {
        buffer->prev = Kernel->virtualBufferTail;
        Kernel->virtualBufferTail->next = buffer;
        Kernel->virtualBufferTail = buffer;
    }

    gcmkVERIFY_OK(gckOS_ReleaseMutex(os, Kernel->virtualBufferLock));

    gcmkFOOTER_NO();
    return gcvSTATUS_OK;

OnError:
    if (buffer->gpuAddress)
    {
#if gcdPROCESS_ADDRESS_SPACE
        gcmkVERIFY_OK(
            gckMMU_FreePages(mmu, buffer->pageTable, buffer->pageCount));
#else
        gcmkVERIFY_OK(
            gckMMU_FreePages(Kernel->mmu, buffer->pageTable, buffer->pageCount));
#endif
    }

    if (buffer->userLogical)
    {
        gcmkVERIFY_OK(
            gckOS_DestroyUserVirtualMapping(os,
                                            buffer->physical,
                                            bytes,
                                            buffer->userLogical));
    }

    if (buffer->kernelLogical)
    {
        gcmkVERIFY_OK(
            gckOS_DestroyKernelVirtualMapping(os,
                                              buffer->physical,
                                              bytes,
                                              buffer->kernelLogical));
    }

    if (buffer->physical)
    {
        gcmkVERIFY_OK(gckOS_FreePagedMemory(os, buffer->physical, bytes));
    }

    gcmkVERIFY_OK(gckOS_Free(os, buffer));

    /* Return the status. */
    gcmkFOOTER();
    return status;
}

gceSTATUS
gckKERNEL_DestroyVirtualCommandBuffer(
    IN gckKERNEL Kernel,
    IN gctSIZE_T Bytes,
    IN gctPHYS_ADDR Physical,
    IN gctPOINTER Logical
    )
{
    gckOS os;
    gckKERNEL kernel;
    gckVIRTUAL_COMMAND_BUFFER_PTR buffer = (gckVIRTUAL_COMMAND_BUFFER_PTR)Physical;

    gcmkHEADER();
    gcmkVERIFY_ARGUMENT(buffer != gcvNULL);

    kernel = buffer->kernel;
    os = kernel->os;

    if (!buffer->userLogical)
    {
        gcmkVERIFY_OK(gckOS_DestroyKernelVirtualMapping(os,
                                                        buffer->physical,
                                                        Bytes,
                                                        Logical));
    }

#if !gcdPROCESS_ADDRESS_SPACE
    gcmkVERIFY_OK(
        gckMMU_FreePages(kernel->mmu, buffer->pageTable, buffer->pageCount));
#endif

    gcmkVERIFY_OK(gckOS_UnmapPages(os, buffer->pageCount, buffer->gpuAddress));

    gcmkVERIFY_OK(gckOS_FreePagedMemory(os, buffer->physical, Bytes));

    gcmkVERIFY_OK(gckOS_AcquireMutex(os, kernel->virtualBufferLock, gcvINFINITE));

    if (buffer == kernel->virtualBufferHead)
    {
        if ((kernel->virtualBufferHead = buffer->next) == gcvNULL)
        {
            kernel->virtualBufferTail = gcvNULL;
        }
    }
    else
    {
        buffer->prev->next = buffer->next;

        if (buffer == kernel->virtualBufferTail)
        {
            kernel->virtualBufferTail = buffer->prev;
        }
        else
        {
            buffer->next->prev = buffer->prev;
        }
    }

    gcmkVERIFY_OK(gckOS_ReleaseMutex(os, kernel->virtualBufferLock));

    gcmkVERIFY_OK(gckOS_Free(os, buffer));

    gcmkFOOTER_NO();
    return gcvSTATUS_OK;
}

gceSTATUS
gckKERNEL_GetGPUAddress(
    IN gckKERNEL Kernel,
    IN gctPOINTER Logical,
    IN gctBOOL InUserSpace,
    OUT gctUINT32 * Address
    )
{
    gceSTATUS status;
    gckVIRTUAL_COMMAND_BUFFER_PTR buffer;
    gctPOINTER start;
    gctUINT32 pid;

    gcmkHEADER_ARG("Logical = %x InUserSpace=%d.", Logical, InUserSpace);

    gcmkVERIFY_OK(gckOS_GetProcessID(&pid));

    status = gcvSTATUS_INVALID_ADDRESS;

    gcmkVERIFY_OK(gckOS_AcquireMutex(Kernel->os, Kernel->virtualBufferLock, gcvINFINITE));

    /* Walk all command buffer. */
    for (buffer = Kernel->virtualBufferHead; buffer != gcvNULL; buffer = buffer->next)
    {
        if (InUserSpace)
        {
            start = buffer->userLogical;
        }
        else
        {
            start = buffer->kernelLogical;
        }

        if (start == gcvNULL)
        {
            continue;
        }

        if (Logical >= start
        && (Logical < (gctPOINTER)((gctUINT8_PTR)start + buffer->pageCount * 4096))
        && pid == buffer->pid
        )
        {
            * Address = buffer->gpuAddress + (gctUINT32)((gctUINT8_PTR)Logical - (gctUINT8_PTR)start);
            status = gcvSTATUS_OK;
            break;
        }
    }

    gcmkVERIFY_OK(gckOS_ReleaseMutex(Kernel->os, Kernel->virtualBufferLock));

    gcmkFOOTER_NO();
    return status;
}

gceSTATUS
gckKERNEL_QueryGPUAddress(
    IN gckKERNEL Kernel,
    IN gctUINT32 GpuAddress,
    OUT gckVIRTUAL_COMMAND_BUFFER_PTR * Buffer
    )
{
    gckVIRTUAL_COMMAND_BUFFER_PTR buffer;
    gctUINT32 start;
    gceSTATUS status = gcvSTATUS_NOT_SUPPORTED;

    gcmkVERIFY_OK(gckOS_AcquireMutex(Kernel->os, Kernel->virtualBufferLock, gcvINFINITE));

    /* Walk all command buffers. */
    for (buffer = Kernel->virtualBufferHead; buffer != gcvNULL; buffer = buffer->next)
    {
        start = (gctUINT32)buffer->gpuAddress;

        if (GpuAddress >= start && GpuAddress < (start + buffer->pageCount * 4096))
        {
            /* Find a range matched. */
            *Buffer = buffer;
            status = gcvSTATUS_OK;
            break;
        }
    }

    gcmkVERIFY_OK(gckOS_ReleaseMutex(Kernel->os, Kernel->virtualBufferLock));

    return status;
}

#if gcdLINK_QUEUE_SIZE
static void
gckLINKQUEUE_Dequeue(
    IN gckLINKQUEUE LinkQueue
    )
{
    gcmkASSERT(LinkQueue->count == gcdLINK_QUEUE_SIZE);

    LinkQueue->count--;
    LinkQueue->front = (LinkQueue->front + 1) % gcdLINK_QUEUE_SIZE;
}

void
gckLINKQUEUE_Enqueue(
    IN gckLINKQUEUE LinkQueue,
    IN gctUINT32 start,
    IN gctUINT32 end
    )
{
    if (LinkQueue->count == gcdLINK_QUEUE_SIZE)
    {
        gckLINKQUEUE_Dequeue(LinkQueue);
    }

    gcmkASSERT(LinkQueue->count < gcdLINK_QUEUE_SIZE);

    LinkQueue->count++;

    LinkQueue->data[LinkQueue->rear].start = start;
    LinkQueue->data[LinkQueue->rear].end = end;

    gcmkVERIFY_OK(
        gckOS_GetProcessID(&LinkQueue->data[LinkQueue->rear].pid));

    LinkQueue->rear = (LinkQueue->rear + 1) % gcdLINK_QUEUE_SIZE;
}

void
gckLINKQUEUE_GetData(
    IN gckLINKQUEUE LinkQueue,
    IN gctUINT32 Index,
    OUT gckLINKDATA * Data
    )
{
    gcmkASSERT(Index >= 0 && Index < gcdLINK_QUEUE_SIZE);

    *Data = &LinkQueue->data[(Index + LinkQueue->front) % gcdLINK_QUEUE_SIZE];
}
#endif

/*
* gckENTRYQUEUE_Enqueue is called with Command->mutexQueue acquired.
*/
gceSTATUS
gckENTRYQUEUE_Enqueue(
    IN gckKERNEL Kernel,
    IN gckENTRYQUEUE Queue,
    IN gctUINT32 physical,
    IN gctUINT32 bytes
    )
{
    gctUINT32 next = (Queue->rear + 1) % gcdENTRY_QUEUE_SIZE;

    if (next == Queue->front)
    {
        /* Queue is full. */
        return gcvSTATUS_INVALID_REQUEST;
    }

    /* Copy data. */
    Queue->data[Queue->rear].physical = physical;
    Queue->data[Queue->rear].bytes = bytes;

    gcmkVERIFY_OK(gckOS_MemoryBarrier(Kernel->os, &Queue->rear));

    /* Update rear. */
    Queue->rear = next;

    return gcvSTATUS_OK;
}

gceSTATUS
gckENTRYQUEUE_Dequeue(
    IN gckENTRYQUEUE Queue,
    OUT gckENTRYDATA * Data
    )
{
    if (Queue->front == Queue->rear)
    {
        /* Queue is empty. */
        return gcvSTATUS_INVALID_REQUEST;
    }

    /* Copy data. */
    *Data = &Queue->data[Queue->front];

    /* Update front. */
    Queue->front = (Queue->front + 1) % gcdENTRY_QUEUE_SIZE;

    return gcvSTATUS_OK;
}

/******************************************************************************\
*************************** Pointer - ID translation ***************************
\******************************************************************************/
#define gcdID_TABLE_LENGTH 1024
typedef struct _gcsINTEGERDB * gckINTEGERDB;
typedef struct _gcsINTEGERDB
{
    gckOS                       os;
    gctPOINTER*                 table;
    gctPOINTER                  mutex;
    gctUINT32                   tableLen;
    gctUINT32                   currentID;
    gctUINT32                   unused;
}
gcsINTEGERDB;

gceSTATUS
gckKERNEL_CreateIntegerDatabase(
    IN gckKERNEL Kernel,
    OUT gctPOINTER * Database
    )
{
    gceSTATUS status;
    gckINTEGERDB database = gcvNULL;

    gcmkHEADER_ARG("Kernel=0x%08X Datbase=0x%08X", Kernel, Database);

    gcmkVERIFY_OBJECT(Kernel, gcvOBJ_KERNEL);
    gcmkVERIFY_ARGUMENT(Database != gcvNULL);

    /* Allocate a database. */
    gcmkONERROR(gckOS_Allocate(
        Kernel->os, gcmSIZEOF(gcsINTEGERDB), (gctPOINTER *)&database));

    gcmkONERROR(gckOS_ZeroMemory(database, gcmSIZEOF(gcsINTEGERDB)));

    /* Allocate a pointer table. */
    gcmkONERROR(gckOS_Allocate(
        Kernel->os, gcmSIZEOF(gctPOINTER) * gcdID_TABLE_LENGTH, (gctPOINTER *)&database->table));

    gcmkONERROR(gckOS_ZeroMemory(database->table, gcmSIZEOF(gctPOINTER) * gcdID_TABLE_LENGTH));

    /* Allocate a database mutex. */
    gcmkONERROR(gckOS_CreateMutex(Kernel->os, &database->mutex));

    /* Initialize. */
    database->currentID = 0;
    database->unused = gcdID_TABLE_LENGTH;
    database->os = Kernel->os;
    database->tableLen = gcdID_TABLE_LENGTH;

    *Database = database;

    gcmkFOOTER_ARG("*Database=0x%08X", *Database);
    return gcvSTATUS_OK;

OnError:
    /* Rollback. */
    if (database)
    {
        if (database->table)
        {
            gcmkOS_SAFE_FREE(Kernel->os, database->table);
        }

        gcmkOS_SAFE_FREE(Kernel->os, database);
    }

    gcmkFOOTER();
    return status;
}

gceSTATUS
gckKERNEL_DestroyIntegerDatabase(
    IN gckKERNEL Kernel,
    IN gctPOINTER Database
    )
{
    gckINTEGERDB database = Database;

    gcmkHEADER_ARG("Kernel=0x%08X Datbase=0x%08X", Kernel, Database);

    gcmkVERIFY_OBJECT(Kernel, gcvOBJ_KERNEL);
    gcmkVERIFY_ARGUMENT(Database != gcvNULL);

    /* Destroy pointer table. */
    gcmkOS_SAFE_FREE(Kernel->os, database->table);

    /* Destroy database mutex. */
    gcmkVERIFY_OK(gckOS_DeleteMutex(Kernel->os, database->mutex));

    /* Destroy database. */
    gcmkOS_SAFE_FREE(Kernel->os, database);

    gcmkFOOTER_NO();
    return gcvSTATUS_OK;
}

gceSTATUS
gckKERNEL_AllocateIntegerId(
    IN gctPOINTER Database,
    IN gctPOINTER Pointer,
    OUT gctUINT32 * Id
    )
{
    gceSTATUS status;
    gckINTEGERDB database = Database;
    gctUINT32 i, unused, currentID, tableLen;
    gctPOINTER * table;
    gckOS os = database->os;
    gctBOOL acquired = gcvFALSE;

    gcmkHEADER_ARG("Database=0x%08X Pointer=0x%08X", Database, Pointer);

    gcmkVERIFY_ARGUMENT(Id != gcvNULL);

    gcmkVERIFY_OK(gckOS_AcquireMutex(os, database->mutex, gcvINFINITE));
    acquired = gcvTRUE;

    if (database->unused < 1)
    {
        /* Extend table. */
        gcmkONERROR(
            gckOS_Allocate(os,
                           gcmSIZEOF(gctPOINTER) * (database->tableLen + gcdID_TABLE_LENGTH),
                           (gctPOINTER *)&table));

        gcmkONERROR(gckOS_ZeroMemory(table + database->tableLen,
                                     gcmSIZEOF(gctPOINTER) * gcdID_TABLE_LENGTH));

        /* Copy data from old table. */
        gckOS_MemCopy(table,
                      database->table,
                      database->tableLen * gcmSIZEOF(gctPOINTER));

        gcmkOS_SAFE_FREE(os, database->table);

        /* Update databse with new allocated table. */
        database->table = table;
        database->currentID = database->tableLen;
        database->tableLen += gcdID_TABLE_LENGTH;
        database->unused += gcdID_TABLE_LENGTH;
    }

    table = database->table;
    currentID = database->currentID;
    tableLen = database->tableLen;
    unused = database->unused;

    /* Connect id with pointer. */
    table[currentID] = Pointer;

    *Id = currentID + 1;

    /* Update the currentID. */
    if (--unused > 0)
    {
        for (i = 0; i < tableLen; i++)
        {
            if (++currentID >= tableLen)
            {
                /* Wrap to the begin. */
                currentID = 0;
            }

            if (table[currentID] == gcvNULL)
            {
                break;
            }
        }
    }

    database->table = table;
    database->currentID = currentID;
    database->tableLen = tableLen;
    database->unused = unused;

    gcmkVERIFY_OK(gckOS_ReleaseMutex(os, database->mutex));
    acquired = gcvFALSE;

    gcmkFOOTER_ARG("*Id=%d", *Id);
    return gcvSTATUS_OK;

OnError:
    if (acquired)
    {
        gcmkVERIFY_OK(gckOS_ReleaseMutex(os, database->mutex));
    }

    gcmkFOOTER();
    return status;
}

gceSTATUS
gckKERNEL_FreeIntegerId(
    IN gctPOINTER Database,
    IN gctUINT32 Id
    )
{
    gceSTATUS status;
    gckINTEGERDB database = Database;
    gckOS os = database->os;
    gctBOOL acquired = gcvFALSE;

    gcmkHEADER_ARG("Database=0x%08X Id=%d", Database, Id);

    gcmkVERIFY_OK(gckOS_AcquireMutex(os, database->mutex, gcvINFINITE));
    acquired = gcvTRUE;

    if (!(Id > 0 && Id <= database->tableLen))
    {
        gcmkONERROR(gcvSTATUS_NOT_FOUND);
    }

    Id -= 1;

    database->table[Id] = gcvNULL;

    if (database->unused++ == 0)
    {
        database->currentID = Id;
    }

    gcmkVERIFY_OK(gckOS_ReleaseMutex(os, database->mutex));
    acquired = gcvFALSE;

    gcmkFOOTER_NO();
    return gcvSTATUS_OK;

OnError:
    if (acquired)
    {
        gcmkVERIFY_OK(gckOS_ReleaseMutex(os, database->mutex));
    }

    gcmkFOOTER();
    return status;
}

gceSTATUS
gckKERNEL_QueryIntegerId(
    IN gctPOINTER Database,
    IN gctUINT32 Id,
    OUT gctPOINTER * Pointer
    )
{
    gceSTATUS status;
    gckINTEGERDB database = Database;
    gctPOINTER pointer;
    gckOS os = database->os;
    gctBOOL acquired = gcvFALSE;

    gcmkHEADER_ARG("Database=0x%08X Id=%d", Database, Id);
    gcmkVERIFY_ARGUMENT(Pointer != gcvNULL);

    gcmkVERIFY_OK(gckOS_AcquireMutex(os, database->mutex, gcvINFINITE));
    acquired = gcvTRUE;

    if (!(Id > 0 && Id <= database->tableLen))
    {
        gcmkONERROR(gcvSTATUS_NOT_FOUND);
    }

    Id -= 1;

    pointer = database->table[Id];

    gcmkVERIFY_OK(gckOS_ReleaseMutex(os, database->mutex));
    acquired = gcvFALSE;

    if (pointer)
    {
        *Pointer = pointer;
    }
    else
    {
        gcmkONERROR(gcvSTATUS_NOT_FOUND);
    }

    gcmkFOOTER_ARG("*Pointer=0x%08X", *Pointer);
    return gcvSTATUS_OK;

OnError:
    if (acquired)
    {
        gcmkVERIFY_OK(gckOS_ReleaseMutex(os, database->mutex));
    }

    gcmkFOOTER();
    return status;
}


gctUINT32
gckKERNEL_AllocateNameFromPointer(
    IN gckKERNEL Kernel,
    IN gctPOINTER Pointer
    )
{
    gceSTATUS status;
    gctUINT32 name;
    gctPOINTER database = Kernel->db->pointerDatabase;

    gcmkHEADER_ARG("Kernel=0x%X Pointer=0x%X", Kernel, Pointer);

    gcmkONERROR(
        gckKERNEL_AllocateIntegerId(database, Pointer, &name));

    gcmkFOOTER_ARG("name=%d", name);
    return name;

OnError:
    gcmkFOOTER();
    return 0;
}

gctPOINTER
gckKERNEL_QueryPointerFromName(
    IN gckKERNEL Kernel,
    IN gctUINT32 Name
    )
{
    gceSTATUS status;
    gctPOINTER pointer = gcvNULL;
    gctPOINTER database = Kernel->db->pointerDatabase;

    gcmkHEADER_ARG("Kernel=0x%X Name=%d", Kernel, Name);

    /* Lookup in database to get pointer. */
    gcmkONERROR(gckKERNEL_QueryIntegerId(database, Name, &pointer));

    gcmkFOOTER_ARG("pointer=0x%X", pointer);
    return pointer;

OnError:
    gcmkFOOTER();
    return gcvNULL;
}

gceSTATUS
gckKERNEL_DeleteName(
    IN gckKERNEL Kernel,
    IN gctUINT32 Name
    )
{
    gctPOINTER database = Kernel->db->pointerDatabase;

    gcmkHEADER_ARG("Kernel=0x%X Name=0x%X", Kernel, Name);

    /* Free name if exists. */
    gcmkVERIFY_OK(gckKERNEL_FreeIntegerId(database, Name));

    gcmkFOOTER_NO();
    return gcvSTATUS_OK;
}

gceSTATUS
gckKERNEL_SetRecovery(
    IN gckKERNEL Kernel,
    IN gctBOOL  Recovery,
    IN gctUINT32 StuckDump
    )
{
    Kernel->recovery = Recovery;

    if (Recovery == gcvFALSE)
    {
        /* Dump stuck information if Recovery is disabled. */
        Kernel->stuckDump = gcmMAX(StuckDump, gcdSTUCK_DUMP_MIDDLE);
    }

    return gcvSTATUS_OK;
}


/*******************************************************************************
***** Shared Buffer ************************************************************
*******************************************************************************/

/*******************************************************************************
**
**  gckKERNEL_CreateShBuffer
**
**  Create shared buffer.
**  The shared buffer can be used across processes. Other process needs call
**  gckKERNEL_MapShBuffer before use it.
**
**  INPUT:
**
**      gckKERNEL Kernel
**          Pointer to an gckKERNEL object.
**
**      gctUINT32 Size
**          Specify the shared buffer size.
**
**  OUTPUT:
**
**      gctSHBUF * ShBuf
**          Pointer to hold return shared buffer handle.
*/
gceSTATUS
gckKERNEL_CreateShBuffer(
    IN gckKERNEL Kernel,
    IN gctUINT32 Size,
    OUT gctSHBUF * ShBuf
    )
{
    gceSTATUS status;
    gcsSHBUF_PTR shBuf = gcvNULL;

    gcmkHEADER_ARG("Kernel=0x%X, Size=%u", Kernel, Size);

    /* Verify the arguments. */
    gcmkVERIFY_OBJECT(Kernel, gcvOBJ_KERNEL);

    if (Size == 0)
    {
        /* Invalid size. */
        gcmkONERROR(gcvSTATUS_INVALID_ARGUMENT);
    }
    else if (Size > 1024)
    {
        /* Limite shared buffer size. */
        gcmkONERROR(gcvSTATUS_OUT_OF_RESOURCES);
    }

    /* Create a shared buffer structure. */
    gcmkONERROR(
        gckOS_Allocate(Kernel->os,
                       sizeof (gcsSHBUF),
                       (gctPOINTER *)&shBuf));

    /* Initialize shared buffer. */
    shBuf->id        = 0;
    shBuf->reference = gcvNULL;
    shBuf->size      = Size;
    shBuf->data      = gcvNULL;

    /* Allocate integer id for this shared buffer. */
    gcmkONERROR(
        gckKERNEL_AllocateIntegerId(Kernel->db->pointerDatabase,
                                    shBuf,
                                    &shBuf->id));

    /* Allocate atom. */
    gcmkONERROR(gckOS_AtomConstruct(Kernel->os, &shBuf->reference));

    /* Set default reference count to 1. */
    gcmkVERIFY_OK(gckOS_AtomSet(Kernel->os, shBuf->reference, 1));

    /* Return integer id. */
    *ShBuf = (gctSHBUF)(gctUINTPTR_T)shBuf->id;

    gcmkFOOTER_ARG("*ShBuf=%u", shBuf->id);
    return gcvSTATUS_OK;

OnError:
    /* Error roll back. */
    if (shBuf != gcvNULL)
    {
        if (shBuf->id != 0)
        {
            gcmkVERIFY_OK(
                gckKERNEL_FreeIntegerId(Kernel->db->pointerDatabase,
                                        shBuf->id));
        }

        gcmkOS_SAFE_FREE(Kernel->os, shBuf);
    }

    gcmkFOOTER();
    return status;
}

/*******************************************************************************
**
**  gckKERNEL_DestroyShBuffer
**
**  Destroy shared buffer.
**  This will decrease reference of specified shared buffer and do actual
**  destroy when no reference on it.
**
**  INPUT:
**
**      gckKERNEL Kernel
**          Pointer to an gckKERNEL object.
**
**      gctSHBUF ShBuf
**          Specify the shared buffer to be destroyed.
**
**  OUTPUT:
**
**      Nothing.
*/
gceSTATUS
gckKERNEL_DestroyShBuffer(
    IN gckKERNEL Kernel,
    IN gctSHBUF ShBuf
    )
{
    gceSTATUS status;
    gcsSHBUF_PTR shBuf;
    gctINT32 oldValue = 0;
    gctBOOL acquired = gcvFALSE;

    gcmkHEADER_ARG("Kernel=0x%X ShBuf=%u",
                   Kernel, (gctUINT32)(gctUINTPTR_T) ShBuf);

    /* Verify the arguments. */
    gcmkVERIFY_OBJECT(Kernel, gcvOBJ_KERNEL);
    gcmkVERIFY_ARGUMENT(ShBuf != gcvNULL);

    /* Acquire mutex. */
    gcmkONERROR(
        gckOS_AcquireMutex(Kernel->os,
                           Kernel->db->pointerDatabaseMutex,
                           gcvINFINITE));
    acquired = gcvTRUE;

    /* Find shared buffer structure. */
    gcmkONERROR(
        gckKERNEL_QueryIntegerId(Kernel->db->pointerDatabase,
                                 (gctUINT32)(gctUINTPTR_T)ShBuf,
                                 (gctPOINTER)&shBuf));

    gcmkASSERT(shBuf->id == (gctUINT32)(gctUINTPTR_T)ShBuf);

    /* Decrease the reference count. */
    gckOS_AtomDecrement(Kernel->os, shBuf->reference, &oldValue);

    if (oldValue == 1)
    {
        /* Free integer id. */
        gcmkVERIFY_OK(
            gckKERNEL_FreeIntegerId(Kernel->db->pointerDatabase,
                                    shBuf->id));

        /* Free atom. */
        gcmkVERIFY_OK(gckOS_AtomDestroy(Kernel->os, shBuf->reference));

        if (shBuf->data)
        {
            gcmkOS_SAFE_FREE(Kernel->os, shBuf->data);
            shBuf->data = gcvNULL;
        }

        /* Free the shared buffer. */
        gcmkOS_SAFE_FREE(Kernel->os, shBuf);
    }

    /* Release the mutex. */
    gcmkVERIFY_OK(
        gckOS_ReleaseMutex(Kernel->os, Kernel->db->pointerDatabaseMutex));
    acquired = gcvFALSE;

    gcmkFOOTER_NO();
    return gcvSTATUS_OK;

OnError:
    if (acquired)
    {
        /* Release the mutex. */
        gcmkVERIFY_OK(
            gckOS_ReleaseMutex(Kernel->os, Kernel->db->pointerDatabaseMutex));
    }

    gcmkFOOTER();
    return status;
}

/*******************************************************************************
**
**  gckKERNEL_MapShBuffer
**
**  Map shared buffer into this process so that it can be used in this process.
**  This will increase reference count on the specified shared buffer.
**  Call gckKERNEL_DestroyShBuffer to dereference.
**
**  INPUT:
**
**      gckKERNEL Kernel
**          Pointer to an gckKERNEL object.
**
**      gctSHBUF ShBuf
**          Specify the shared buffer to be mapped.
**
**  OUTPUT:
**
**      Nothing.
*/
gceSTATUS
gckKERNEL_MapShBuffer(
    IN gckKERNEL Kernel,
    IN gctSHBUF ShBuf
    )
{
    gceSTATUS status;
    gcsSHBUF_PTR shBuf;
    gctINT32 oldValue = 0;
    gctBOOL acquired = gcvFALSE;

    gcmkHEADER_ARG("Kernel=0x%X ShBuf=%u",
                   Kernel, (gctUINT32)(gctUINTPTR_T) ShBuf);

    /* Verify the arguments. */
    gcmkVERIFY_OBJECT(Kernel, gcvOBJ_KERNEL);
    gcmkVERIFY_ARGUMENT(ShBuf != gcvNULL);

    /* Acquire mutex. */
    gcmkONERROR(
        gckOS_AcquireMutex(Kernel->os,
                           Kernel->db->pointerDatabaseMutex,
                           gcvINFINITE));
    acquired = gcvTRUE;

    /* Find shared buffer structure. */
    gcmkONERROR(
        gckKERNEL_QueryIntegerId(Kernel->db->pointerDatabase,
                                 (gctUINT32)(gctUINTPTR_T)ShBuf,
                                 (gctPOINTER)&shBuf));

    gcmkASSERT(shBuf->id == (gctUINT32)(gctUINTPTR_T)ShBuf);

    /* Increase the reference count. */
    gckOS_AtomIncrement(Kernel->os, shBuf->reference, &oldValue);

    /* Release the mutex. */
    gcmkVERIFY_OK(
        gckOS_ReleaseMutex(Kernel->os, Kernel->db->pointerDatabaseMutex));
    acquired = gcvFALSE;

    gcmkFOOTER_NO();
    return gcvSTATUS_OK;

OnError:
    if (acquired)
    {
        /* Release the mutex. */
        gcmkVERIFY_OK(
            gckOS_ReleaseMutex(Kernel->os, Kernel->db->pointerDatabaseMutex));
    }

    gcmkFOOTER();
    return status;
}

/*******************************************************************************
**
**  gckKERNEL_WriteShBuffer
**
**  Write user data into shared buffer.
**
**  INPUT:
**
**      gckKERNEL Kernel
**          Pointer to an gckKERNEL object.
**
**      gctSHBUF ShBuf
**          Specify the shared buffer to be written to.
**
**      gctPOINTER UserData
**          User mode pointer to hold the source data.
**
**      gctUINT32 ByteCount
**          Specify number of bytes to write. If this is larger than
**          shared buffer size, gcvSTATUS_INVALID_ARGUMENT is returned.
**
**  OUTPUT:
**
**      Nothing.
*/
gceSTATUS
gckKERNEL_WriteShBuffer(
    IN gckKERNEL Kernel,
    IN gctSHBUF ShBuf,
    IN gctPOINTER UserData,
    IN gctUINT32 ByteCount
    )
{
    gceSTATUS status;
    gcsSHBUF_PTR shBuf;
    gctBOOL acquired = gcvFALSE;

    gcmkHEADER_ARG("Kernel=0x%X ShBuf=%u UserData=0x%X ByteCount=%u",
                   Kernel, (gctUINT32)(gctUINTPTR_T) ShBuf, UserData, ByteCount);

    /* Verify the arguments. */
    gcmkVERIFY_OBJECT(Kernel, gcvOBJ_KERNEL);
    gcmkVERIFY_ARGUMENT(ShBuf != gcvNULL);

    /* Acquire mutex. */
    gcmkONERROR(
        gckOS_AcquireMutex(Kernel->os,
                           Kernel->db->pointerDatabaseMutex,
                           gcvINFINITE));
    acquired = gcvTRUE;

    /* Find shared buffer structure. */
    gcmkONERROR(
        gckKERNEL_QueryIntegerId(Kernel->db->pointerDatabase,
                                 (gctUINT32)(gctUINTPTR_T)ShBuf,
                                 (gctPOINTER)&shBuf));

    gcmkASSERT(shBuf->id == (gctUINT32)(gctUINTPTR_T)ShBuf);

    if ((ByteCount > shBuf->size) ||
        (ByteCount == 0) ||
        (UserData  == gcvNULL))
    {
        /* Exceeds buffer max size or invalid. */
        gcmkONERROR(gcvSTATUS_INVALID_ARGUMENT);
    }

    if (shBuf->data == gcvNULL)
    {
        /* Allocate buffer data when first time write. */
        gcmkONERROR(gckOS_Allocate(Kernel->os, ByteCount, &shBuf->data));
    }

    /* Copy data from user. */
    gcmkONERROR(
        gckOS_CopyFromUserData(Kernel->os,
                               shBuf->data,
                               UserData,
                               ByteCount));

    /* Release the mutex. */
    gcmkVERIFY_OK(
        gckOS_ReleaseMutex(Kernel->os, Kernel->db->pointerDatabaseMutex));
    acquired = gcvFALSE;

    gcmkFOOTER_NO();
    return gcvSTATUS_OK;

OnError:
    if (acquired)
    {
        /* Release the mutex. */
        gcmkVERIFY_OK(
            gckOS_ReleaseMutex(Kernel->os, Kernel->db->pointerDatabaseMutex));
    }

    gcmkFOOTER();
    return status;
}

/*******************************************************************************
**
**  gckKERNEL_ReadShBuffer
**
**  Read data from shared buffer and copy to user pointer.
**
**  INPUT:
**
**      gckKERNEL Kernel
**          Pointer to an gckKERNEL object.
**
**      gctSHBUF ShBuf
**          Specify the shared buffer to be read from.
**
**      gctPOINTER UserData
**          User mode pointer to save output data.
**
**      gctUINT32 ByteCount
**          Specify number of bytes to read.
**          If this is larger than shared buffer size, only avaiable bytes are
**          copied. If smaller, copy requested size.
**
**  OUTPUT:
**
**      gctUINT32 * BytesRead
**          Pointer to hold how many bytes actually read from shared buffer.
*/
gceSTATUS
gckKERNEL_ReadShBuffer(
    IN gckKERNEL Kernel,
    IN gctSHBUF ShBuf,
    IN gctPOINTER UserData,
    IN gctUINT32 ByteCount,
    OUT gctUINT32 * BytesRead
    )
{
    gceSTATUS status;
    gcsSHBUF_PTR shBuf;
    gctUINT32 bytes;
    gctBOOL acquired = gcvFALSE;

    gcmkHEADER_ARG("Kernel=0x%X ShBuf=%u UserData=0x%X ByteCount=%u",
                   Kernel, (gctUINT32)(gctUINTPTR_T) ShBuf, UserData, ByteCount);

    /* Verify the arguments. */
    gcmkVERIFY_OBJECT(Kernel, gcvOBJ_KERNEL);
    gcmkVERIFY_ARGUMENT(ShBuf != gcvNULL);

    /* Acquire mutex. */
    gcmkONERROR(
        gckOS_AcquireMutex(Kernel->os,
                           Kernel->db->pointerDatabaseMutex,
                           gcvINFINITE));
    acquired = gcvTRUE;

    /* Find shared buffer structure. */
    gcmkONERROR(
        gckKERNEL_QueryIntegerId(Kernel->db->pointerDatabase,
                                 (gctUINT32)(gctUINTPTR_T)ShBuf,
                                 (gctPOINTER)&shBuf));

    gcmkASSERT(shBuf->id == (gctUINT32)(gctUINTPTR_T)ShBuf);

    if (shBuf->data == gcvNULL)
    {
        *BytesRead = 0;

        /* No data in shared buffer, skip copy. */
        status = gcvSTATUS_SKIP;
        goto OnError;
    }
    else if (ByteCount == 0)
    {
        /* Invalid size to read. */
        gcmkONERROR(gcvSTATUS_INVALID_ARGUMENT);
    }

    /* Determine bytes to copy. */
    bytes = (ByteCount < shBuf->size) ? ByteCount : shBuf->size;

    /* Copy data to user. */
    gcmkONERROR(
        gckOS_CopyToUserData(Kernel->os,
                             shBuf->data,
                             UserData,
                             bytes));

    /* Return copied size. */
    *BytesRead = bytes;

    /* Release the mutex. */
    gcmkVERIFY_OK(
        gckOS_ReleaseMutex(Kernel->os, Kernel->db->pointerDatabaseMutex));
    acquired = gcvFALSE;

    gcmkFOOTER_ARG("*BytesRead=%u", bytes);
    return gcvSTATUS_OK;

OnError:
    if (acquired)
    {
        /* Release the mutex. */
        gcmkVERIFY_OK(
            gckOS_ReleaseMutex(Kernel->os, Kernel->db->pointerDatabaseMutex));
    }

    gcmkFOOTER();
    return status;
}


/*******************************************************************************
***** Test Code ****************************************************************
*******************************************************************************/

