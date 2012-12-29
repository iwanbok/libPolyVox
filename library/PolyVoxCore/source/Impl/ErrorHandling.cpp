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

#ifndef POLYVOX_THROW_ENABLED
	namespace PolyVox
	{
		void defaultThrowHandler(std::exception& e, const char* file, int line)
		{
			std::cerr << std::endl << std::endl; \
			std::cerr << "    PolyVox exception thrown!" << std::endl; \
			std::cerr << "    =========================" << std::endl; \
			std::cerr << "    PolyVox has tried to throw an exception but it was built without support" << std::endl; \
			std::cerr << "    for exceptions. In this scenario PolyVox will call a 'throw handler'" << std::endl; \
			std::cerr << "    and this message is being printed by the default throw handler." << std::endl << std::endl; \

			std::cerr << "    If you don't want to enable exceptions then you should try to determine why" << std::endl; \
			std::cerr << "    this exception was thrown and make sure it doesn't happen again. If it was" << std::endl; \
			std::cerr << "    due to something like an invalid argument to a function then you should be" << std::endl; \
			std::cerr << "    able to fix it quite easily by validating parameters as appropriate. More" << std::endl; \
			std::cerr << "    complex exception scenarios (out of memory, etc) might be harder to fix and" << std::endl; \
			std::cerr << "    you should replace this default handler with something which is more" << std::endl; \
			std::cerr << "    meaningful to your users." << std::endl << std::endl; \

			std::cerr << "    Exception details" << std::endl; \
			std::cerr << "    -----------------" << std::endl; \
			std::cerr << "    Line:    " << line << std::endl; \
			std::cerr << "    File:    " << file << std::endl; \
			std::cerr << "    Message: " << e.what() << std::endl << std::endl; \

			POLYVOX_HALT(); \
		}

		ThrowHandler& getThrowHandlerInstance()
		{
			static ThrowHandler s_fThrowHandler = &defaultThrowHandler;
			return s_fThrowHandler;
		}

		ThrowHandler getThrowHandler()
		{
			return getThrowHandlerInstance();
		}

		void setThrowHandler(ThrowHandler fNewHandler)
		{
			getThrowHandlerInstance() = fNewHandler;
		}
	}
#endif
