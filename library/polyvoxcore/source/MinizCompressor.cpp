#include "PolyVoxCore/MinizCompressor.h"

// Diable things we don't need, and in particular the zlib compatible names which
// would cause conflicts if a user application is using both PolyVox and zlib.
#define MINIZ_NO_STDIO
#define MINIZ_NO_ARCHIVE_APIS
#define MINIZ_NO_TIME
//#define MINIZ_NO_ZLIB_APIS
#define MINIZ_NO_ZLIB_COMPATIBLE_NAMES
//#define MINIZ_NO_MALLOC

#include "PolyVoxCore/Impl/ErrorHandling.h"
// For some unknown reason the miniz library is supplied only as a 
// single .c file without a header. Apparently the only way to use 
// it is then to #include it directly which is what the examples do.
#include "PolyVoxCore/Impl/miniz.c"

#include <sstream>

using namespace std;

namespace PolyVox
{
	MinizCompressor::MinizCompressor()
	{
	}

	MinizCompressor::~MinizCompressor()
	{
	}

	uint32_t MinizCompressor::getMaxCompressedSize(uint32_t uUncompressedInputSize)
	{
		return static_cast<uint32_t>(mz_compressBound(static_cast<mz_ulong>(uUncompressedInputSize)));
	}

	uint32_t MinizCompressor::compress(void* pSrcData, uint32_t uSrcLength, void* pDstData, uint32_t uDstLength)
	{
		mz_ulong ulDstLength = uDstLength;

		// Do the compression
		int result = mz_compress((unsigned char*)pDstData, &ulDstLength, (const unsigned char*) pSrcData, uSrcLength);
		if(result != MZ_OK)
		{
			stringstream ss;
			ss << "mz_compress() failed with return code '" << result << "'";
			POLYVOX_THROW(std::runtime_error, ss.str());
		}

		// Return the number of bytes written to the output.
		return ulDstLength;
	}

	uint32_t MinizCompressor::decompress(void* pSrcData, uint32_t uSrcLength, void* pDstData, uint32_t uDstLength)
	{
		mz_ulong ulDstLength = uDstLength;

		int result = mz_uncompress((unsigned char*) pDstData, &ulDstLength, (const unsigned char*) pSrcData, uSrcLength);
		if(result != MZ_OK)
		{
			stringstream ss;
			ss << "mz_uncompress() failed with return code '" << result << "'";
			POLYVOX_THROW(std::runtime_error, ss.str());
		}

		return ulDstLength;
	}
}
