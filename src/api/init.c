/*
The MIT License (MIT)

Copyright (c) 2016 Paul Kramme

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#include"init.h"

static short unsigned int global_init = 0;

int init(int arg)
{
	switch(arg)
	{
		case 0:
			switch(global_init)
			{
				case 1:
					bcm2835_close();
					global_init = 0;
					return 0;
				case 0:
					return 1;
			}
		case 1:
			switch(global_init)
			{
				case 1:
					return 1;
				case 0:
#ifdef DEBUG
					bcm2835_set_debug(1);
#endif
					if(!bcm2835_init())
                                        {
                                             exit(1);
					}
					global_init = 1;
					return 0;
			}
	}
	return 1;
}

