/*******************************************************************************
Copyright (c) 2005-2009 David Williams

This software is provided 'as-is', without any express or implied
warranty. In no event will the authors be held liable for any damages
arising from the use of this software.

Permission is granted to anyone to use this software for any purpose,
including commercial applications, and to alter it and redistribute it
freely, subject to the following restrictions:

    1. The origin of this software must not be misrepresented; you must not
    claim that you wrote the original software. If you use this software
    in a product, an acknowledgment in the product documentation would be
    appreciated but is not required.

    2. Altered source versions must be plainly marked as such, and must not be
    misrepresented as being the original software.

    3. This notice may not be removed or altered from any source
    distribution. 	
*******************************************************************************/

#ifndef __PolyVox_Pager_H__
#define __PolyVox_Pager_H__

#include "PolyVoxCore/Impl/Block.h"
#include "PolyVoxCore/Impl/TypeDef.h"

#include "PolyVoxCore/ConstVolumeProxy.h"

namespace PolyVox
{
	/**
	 * Provides an interface for performing paging of data.
	 */
	template <typename VoxelType>
	class Pager
	{
	public:
		/// Constructor
		Pager() {};
		/// Destructor
		virtual ~Pager() {};

		virtual void pageIn(const Region& region, Block<VoxelType>* pBlockData) = 0;
		virtual void pageOut(const Region& region, Block<VoxelType>* pBlockData) = 0;

		virtual void dataRequiredHandler(const ConstVolumeProxy<VoxelType>& volumeProxy, const Region& region)
		{
			POLYVOX_ASSERT(false, "NOT IMPLEMENTED");
		}

		virtual void dataOverflowHandler(const ConstVolumeProxy<VoxelType>& volumeProxy, const Region& region)
		{
			POLYVOX_ASSERT(false, "NOT IMPLEMENTED");
		}
	};
}

#endif //__PolyVox_Pager_H__
