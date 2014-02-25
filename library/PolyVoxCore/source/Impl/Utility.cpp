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

#include "PolyVoxCore/Impl/ErrorHandling.h"
#include "PolyVoxCore/Impl/Utility.h"

namespace PolyVox
{
	//Note: this function only works for inputs which are a power of two and not zero
	//If this is not the case then the output is undefined.
	uint8_t logBase2(uint32_t uInput)
	{
		//Release mode validation
		if(uInput == 0)
		{
			POLYVOX_THROW(std::invalid_argument, "Cannot compute the log of zero.");
		}
		if(!isPowerOf2(uInput))
		{
			POLYVOX_THROW(std::invalid_argument, "Input must be a power of two in order to compute the log.");
		}

		uint32_t uResult = 0;
		while( (uInput >> uResult) != 0)
		{
			++uResult;
		}
		return static_cast<uint8_t>(uResult-1);
	}


	bool isPowerOf2(uint32_t uInput)
	{
		if(uInput == 0)
			return false;
		else
			return ((uInput & (uInput-1)) == 0);
	}

	// http://graphics.stanford.edu/~seander/bithacks.html#RoundUpPowerOf2
	uint32_t upperPowerOfTwo(uint32_t v)
	{
		v--;
		v |= v >> 1;
		v |= v >> 2;
		v |= v >> 4;
		v |= v >> 8;
		v |= v >> 16;
		v++;
		return v;
	}
}
