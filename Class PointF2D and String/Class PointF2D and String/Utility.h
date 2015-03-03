#ifndef __UTILITY_H__
#define __UTILITY_H__


template<classKIND> void swap(KIND& a, KIND& b)
{
	KIND tmp;
	tmp = a;
	a = b;
	b = tmp;
}

#endif
