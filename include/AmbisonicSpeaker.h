/*############################################################################*/
/*#                                                                          #*/
/*#  Ambisonic C++ Library                                                   #*/
/*#  CAmbisonicSpeaker - Ambisonic Speaker                                   #*/
/*#  Copyright © 2007 Aristotel Digenis                                      #*/
/*#                                                                          #*/
/*#  Filename:      AmbisonicSpeaker.h                                       #*/
/*#  Version:       0.1                                                      #*/
/*#  Date:          19/05/2007                                               #*/
/*#  Author(s):     Aristotel Digenis                                        #*/
/*#  Licence:       MIT                                                      #*/
/*#                                                                          #*/
/*############################################################################*/


#ifndef _AMBISONIC_SPEAKER_H
#define _AMBISONIC_SPEAKER_H

#include "AmbisonicSource.h"
#include "BFormat.h"

/// Ambisonic speaker

/** This is a speaker class to be used in the decoder. */

class CAmbisonicSpeaker : public CAmbisonicSource
{
public:
    CAmbisonicSpeaker();
    ~CAmbisonicSpeaker();

    /** Re-create the object for the given configuration. Previous data is
     *  lost. The last argument is not used, it is just there to match with
     *  the base class's form. Returns true if successful.
     * @param nOrder    Order of the signal to process.
     * @param b3D       True if the signal is 3D.
     * @param nMisc     Unused.
     * @return          Returns true if successfully configured.
     */
    virtual bool Configure(unsigned nOrder, bool b3D, unsigned nMisc);

    /** Recalculate coefficients, and apply normalisation factors. */
    void Refresh();

    /** Decode B-Format to speaker feed.
     * @param pBFSrc    B-Format signal to decode.
     * @param nSamples  Number of samples to decode.
     * @param pfDst     Mono speaker signal output.
     */
    void Process(CBFormat* pBFSrc, unsigned nSamples, float* pfDst);
};

#endif // _AMBISONIC_SPEAKER_H
