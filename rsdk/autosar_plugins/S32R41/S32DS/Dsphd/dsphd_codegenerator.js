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
 * To be used with S32 Configuration Tool. See Software License Agreement of S32 Configuration Tool.
 */

function Dsphd_CodeGenerator(configSet, currentVariant, variantsList) {

    /* Returns the class name */
    this.toString = function()
    {
        return "Dsphd_CodeGenerator";
    }

    var generateInputList = [
        "Dsphd_PCcfg.h"
    ];
    var generateOutputList = [
        "Dsphd_PCcfg.h"
    ];

    for (var i = 0; i < generateInputList.length; ++i) {
        generateFile(generateInputList[i], arguments, generateOutputList[i]);
    }
}