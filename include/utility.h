#ifndef UTILITY_H
#define UTILITY_H

/*-------------------------------------
Types
-------------------------------------*/

typedef enum {
    STATUS_FAILURE,
    STATUS_SUCCESS
} ResultStatus;

/*-------------------------------------
Procedures
-------------------------------------*/

static inline ResultStatus UTL_FillUInt32( uint32_t * dst, uint32_t count, uint32_t value )
    {
    if( dst == NULL ) return STATUS_FAILURE;
    for(; count != 0; ++dst, --count ) (*dst) = value;
    return STATUS_SUCCESS;
    }

#endif