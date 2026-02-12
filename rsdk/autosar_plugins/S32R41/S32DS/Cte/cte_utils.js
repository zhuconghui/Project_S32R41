/*
 * Copyright 2024 NXP
 * NXP Confidential and Proprietary. This software is owned or controlled by NXP and
 * may only be used strictly in accordance with the applicable license terms.  By
 * expressly accepting such terms or by downloading, installing, activating and/or
 * otherwise using the software, you are agreeing that you have read, and that you
 * agree to comply with and are bound by, such license terms.  If you do not agree to
 * be bound by the applicable license terms, then you may not retain, install, activate or
 * otherwise use the software.
 *
 * To be used with S32DS Configuration Tool. See Software License Agreement of S32DS Configuration Tool.
 * 
 * Accessories functions for CTE S32DS peripheral module.
 *
 */

/*
*   Function to check the specified platform matches the required name/partial name.
*   The string is checked only at the beginning of the platform name.
*   Input : the component name to be checked (usually), the string to be checked
*   Output : true/false, accordin to the complete match of the string
*/
function CteIsPlatformMatch(platformName, platformMatch)
{
    return (platformName.match(platformMatch) == platformMatch);
}

/*
*   Function to get the generic platform name, based on the complete part number received
*   Input : the part number
*   Output : the generic platform name
*/
function CteGetPlatform(partNumber)
{
    if(partNumber.substr(0,4) == "S32R")
    {
        // it is a S32R processor
        return(partNumber.substr(0,6));
    }
    else
    {
        // it is not S32R
        if(partNumber.substr(0,4) == "SAF8")
        {
            return(partNumber.substr(0,5));
        }
        return "Not a Radar chip";
    }
}

/*
*   Function to check the specified platform matches the required name/partial name.
*   The string is checked only at the beginning of the platform name.
*   Input : the component name to be checked (usually), the string to be checked
*   Output : true/false, accordin to the complete match of the string
*/
function CteIncrementByOne(inputNumber)
{
    return (parseInt(inputNumber,10) + 1).toString();
}

function CteGetSignalDefs(size, isNullable)
{
    var arrSize = parseInt(size, 10);
    var IDs = new Array(arrSize);
    var str = "outputDefTable_";
    
    if(isNullable)
    {
        IDs[0] = "NULL_PTR";
        for (var idx = 0; idx < arrSize; idx++)
        {
            IDs[idx+1] = str.concat('', idx.toString());
        }
    }
    else
    {
        for (var idx = 0; idx < arrSize; idx++)
        {
            IDs[idx] = str.concat('', idx.toString());
        }
    }
    return IDs;
}

function CteGetTimeTables(startIndex, size)
{
    var arrSize = parseInt(size, 10);
    var startIdx = parseInt(startIndex, 10);
    var IDs = new Array(arrSize);
    var str = "timeTable_";
    
    if(startIndex = 0)
    {
        IDs[0] = "NULL_PTR";
    }
    else
    {
        for (var idx = 0; idx < arrSize; idx++)
        {
            IDs[idx] = str.concat('', startIdx.toString());
            startIdx++;
        }
    }
    
    return IDs;
}

function getIndex(inputString)
{
    if(isNaN(parseInt(inputString.slice(-1),10)))
    {
        return 0;
    }
    else
    {
        return parseInt(inputString.slice(-1),10); /* Get last character, convert to integer */
    }
}
