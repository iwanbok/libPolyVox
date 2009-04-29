#pragma region License
/******************************************************************************
This file is part of the PolyVox library
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
#pragma endregion

#ifndef __PolyVox_SurfaceVertex_H__
#define __PolyVox_SurfaceVertex_H__

#include "PolyVoxImpl/TypeDef.h"
#include "Vector.h"

namespace PolyVox
{	
	class POLYVOXCORE_API SurfaceVertex
	{
	public:	
		SurfaceVertex();
		SurfaceVertex(Vector3DFloat positionToSet, float materialToSet);
		SurfaceVertex(Vector3DFloat positionToSet, Vector3DFloat normalToSet, float materialToSet);	

		float getMaterial(void) const;
		const Vector3DFloat& getNormal(void) const;
		const Vector3DFloat& getPosition(void) const;	
	
		void setMaterial(float materialToSet);
		void setNormal(const Vector3DFloat& normalToSet);
		void setPosition(const Vector3DFloat& positionToSet);

	public:		
		Vector3DFloat position;
		Vector3DFloat normal;
		float material;
			
	};

	
	

	//bool operator < (const SurfaceVertexIterator& lhs, const SurfaceVertexIterator& rhs);
}

#endif
