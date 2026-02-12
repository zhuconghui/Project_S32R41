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
 * Accessories functions for CSI2 S32DS peripheral module.
 *
 */

/*
*   Function to check the specified platform matches the required name/partial name.
*   The string is checked only at the beginning of the platform name.
*   Input : the component name to be checked (usually), the string to be checked
*   Output : true/false, accordin to the complete match of the string
*/
function Csi2IsPlatformMatch(platformName, platformMatch)
{
    return (platformName.match(platformMatch) == platformMatch);
}

/*
*   Function to get the generic platform name, based on the complete part number received
*   Input : the part number
*   Output : the generic platform name
*/
function Csi2GetPlatform(partNumber)
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

/*  Function to detect the minimum frequency to be set for CSI2-PHY clock lane
*   Input : platform name
*   Output : minimum frequency value
*/
function Csi2MinFreq(platformName)
{
    if(platformName.substr(0,4) == "S32R")
        return 80;
    else
        return 0;
}

/*  Function to convert the selection used for lanes in number value
*   Input : lanes selection
*   Output : the number of lanes used, 1...4
*/
function GetNumLanes(setupArray)
{
    var val = 0;
    switch(setupArray)
    {
        case "One___lane" : val =  "x"; break;
        case "Two___lanes": val =  "xx"; break;
        case "Three_lanes": val =  "xxx"; break;
        case "Four__lanes": val =  "xxxx"; break;
    }
    return val;
}

