/*
 * ExtInt.c
 *
 *  Created on: Sep 23, 2023
 *      Author: ahmad
 */
#include "StdTypes.h"
#include "Macros.h"
#include "Registers.h"
#include "ExtInt.h"

StdReturnType ExtInt_SetSenseControl (ExtInt_SourceType source, ExtInt_SenseType sense)
{
    StdReturnType retVal = E_OK;
    if (EXTINT_SOURCE_INT0 == source)
    {
        switch (sense)
        {
        case EXTINT_SENSE_LOW_LEVEL:
            CLR_BIT(MCUCR, 0);
            CLR_BIT(MCUCR, 1);
            break;
        case EXTINT_SENSE_ON_CHANGE:
            SET_BIT(MCUCR, 0);
            CLR_BIT(MCUCR, 1);
            break;
        case EXTINT_SENSE_FALLING_EDGE:
            CLR_BIT(MCUCR, 0);
            SET_BIT(MCUCR, 1);
            break;
        case EXTINT_SENSE_RISING_EDGE:
            SET_BIT(MCUCR, 0);
            SET_BIT(MCUCR, 1);
            break;
        default:
            retVal = E_NOT_OK;
            break;
        }
    }
    else if (EXTINT_SOURCE_INT1 == source)
    {
        switch (sense)
        {
        case EXTINT_SENSE_LOW_LEVEL:
            CLR_BIT(MCUCR, 2);
            CLR_BIT(MCUCR, 3);
            break;
        case EXTINT_SENSE_ON_CHANGE:
            SET_BIT(MCUCR, 2);
            CLR_BIT(MCUCR, 3);
            break;
        case EXTINT_SENSE_FALLING_EDGE:
            CLR_BIT(MCUCR, 2);
            SET_BIT(MCUCR, 3);
            break;
        case EXTINT_SENSE_RISING_EDGE:
            SET_BIT(MCUCR, 2);
            SET_BIT(MCUCR, 3);
            break;
        default:
            retVal = E_NOT_OK;
            break;
        }
    }
    else if (EXTINT_SOURCE_INT2 == source)
    {
        switch (sense)
        {
        case EXTINT_SENSE_FALLING_EDGE:
            CLR_BIT(MCUCSR, 6);
            break;
        case EXTINT_SENSE_RISING_EDGE:
            SET_BIT(MCUCSR, 6);
            break;
        default:
            retVal = E_NOT_OK;
            break;
        }
    }
    else
    {
        retVal = E_NOT_OK;
    }
    return retVal;
}

StdReturnType ExtInt_EnableInterrupt (ExtInt_SourceType source)
{
    StdReturnType retVal = E_OK;
    if (EXTINT_SOURCE_INT0 == source)
    {
        SET_BIT(GICR, 6);
    }
    else if (EXTINT_SOURCE_INT1 == source)
    {
        SET_BIT(GICR, 7);
    }
    else if (EXTINT_SOURCE_INT2 == source)
    {
        SET_BIT(GICR, 5);
    }
    else 
    {
        retVal = E_NOT_OK;
    }
    return retVal;
}

StdReturnType ExtInt_DisableInterrupt (ExtInt_SourceType source)
{
    StdReturnType retVal = E_OK;
    if (EXTINT_SOURCE_INT0 == source)
    {
        CLR_BIT(GICR, 6);
    }
    else if (EXTINT_SOURCE_INT1 == source)
    {
        CLR_BIT(GICR, 7);
    }
    else if (EXTINT_SOURCE_INT2 == source)
    {
        CLR_BIT(GICR, 5);
    }
    else 
    {
        retVal = E_NOT_OK;
    }
    return retVal;
}
