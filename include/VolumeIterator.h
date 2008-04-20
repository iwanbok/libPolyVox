/******************************************************************************
This file is part of a voxel plugin for OGRE
Copyright (C) 2006  David Williams

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
******************************************************************************/
#ifndef __VolumeIterator_H__
#define __VolumeIterator_H__

#include "boost/cstdint.hpp"

#include "PolyVoxForwardDeclarations.h"
#include "TypeDef.h"
#include "Vector.h"

namespace PolyVox
{
	template <typename VoxelType>
	class VolumeIterator
	{
	public:
		VolumeIterator(Volume<VoxelType>& volume);
		~VolumeIterator();

		void setVoxel(VoxelType value);
		VoxelType getVoxel(void);

		VoxelType getVoxelAt(const boost::uint16_t xPosition, const boost::uint16_t yPosition, const boost::uint16_t zPosition) const;
		void setVoxelAt(const boost::uint16_t xPosition, const boost::uint16_t yPosition, const boost::uint16_t zPosition, const VoxelType value);

		float getAveragedVoxelAt(const boost::uint16_t xPosition, const boost::uint16_t yPosition, const boost::uint16_t zPosition, boost::uint16_t size) const;

		//FIXME - this shouldn't return float vector
		Vector3DFloat getCentralDifferenceGradient(void) const;
		Vector3DFloat getAveragedCentralDifferenceGradient(void) const;
		Vector3DFloat getSobelGradient(void) const;

		boost::uint16_t getPosX(void);
		boost::uint16_t getPosY(void);
		boost::uint16_t getPosZ(void);

		void setPosition(boost::uint16_t xPos, boost::uint16_t yPos, boost::uint16_t zPos);
		void setValidRegion(boost::uint16_t xFirst, boost::uint16_t yFirst, boost::uint16_t zFirst, boost::uint16_t xLast, boost::uint16_t yLast, boost::uint16_t zLast);
		void moveForwardInRegion(void);

		bool isValidForRegion(void);

		VoxelType peekVoxel1nx1ny1nz(void) const;
		VoxelType peekVoxel1nx1ny0pz(void) const;
		VoxelType peekVoxel1nx1ny1pz(void) const;
		VoxelType peekVoxel1nx0py1nz(void) const;
		VoxelType peekVoxel1nx0py0pz(void) const;
		VoxelType peekVoxel1nx0py1pz(void) const;
		VoxelType peekVoxel1nx1py1nz(void) const;
		VoxelType peekVoxel1nx1py0pz(void) const;
		VoxelType peekVoxel1nx1py1pz(void) const;

		VoxelType peekVoxel0px1ny1nz(void) const;
		VoxelType peekVoxel0px1ny0pz(void) const;
		VoxelType peekVoxel0px1ny1pz(void) const;
		VoxelType peekVoxel0px0py1nz(void) const;
		VoxelType peekVoxel0px0py0pz(void) const;
		VoxelType peekVoxel0px0py1pz(void) const;
		VoxelType peekVoxel0px1py1nz(void) const;
		VoxelType peekVoxel0px1py0pz(void) const;
		VoxelType peekVoxel0px1py1pz(void) const;

		VoxelType peekVoxel1px1ny1nz(void) const;
		VoxelType peekVoxel1px1ny0pz(void) const;
		VoxelType peekVoxel1px1ny1pz(void) const;
		VoxelType peekVoxel1px0py1nz(void) const;
		VoxelType peekVoxel1px0py0pz(void) const;
		VoxelType peekVoxel1px0py1pz(void) const;
		VoxelType peekVoxel1px1py1nz(void) const;
		VoxelType peekVoxel1px1py0pz(void) const;
		VoxelType peekVoxel1px1py1pz(void) const;

	private:
		//The current volume
		Volume<VoxelType>& mVolume;

		//The current position in the volume
		boost::uint16_t mXPosInVolume;
		boost::uint16_t mYPosInVolume;
		boost::uint16_t mZPosInVolume;

		//The position of the current block
		boost::uint16_t mXBlock;
		boost::uint16_t mYBlock;
		boost::uint16_t mZBlock;

		//The offset into the current block
		boost::uint16_t mXPosInBlock;
		boost::uint16_t mYPosInBlock;
		boost::uint16_t mZPosInBlock;

		//Other current position information
		VoxelType* mCurrentVoxel;
		boost::uint32_t mBlockIndexInVolume;
		boost::uint32_t mVoxelIndexInBlock;

		boost::uint16_t mXRegionFirst;
		boost::uint16_t mYRegionFirst;
		boost::uint16_t mZRegionFirst;
		boost::uint16_t mXRegionLast;
		boost::uint16_t mYRegionLast;
		boost::uint16_t mZRegionLast;

		boost::uint16_t mXRegionFirstBlock;
		boost::uint16_t mYRegionFirstBlock;
		boost::uint16_t mZRegionFirstBlock;
		boost::uint16_t mXRegionLastBlock;
		boost::uint16_t mYRegionLastBlock;
		boost::uint16_t mZRegionLastBlock;

		bool mIsValidForRegion;
	};
}

#include "VolumeIterator.inl"

#endif
