//
//
//

#include "usrp_io.h"

void* tx_nco_callback(short *_I, short *_Q, unsigned int _n, void * _userdata);
void* rx_display_callback(short *_I, short *_Q, unsigned int _n, void * _userdata);

int main() {
    // options
    float   tx_freq     = 462e6f;
    float   rx_freq     = 427e6f;
    int     tx_decim    = 256;
    int     rx_decim    = 256;

    // create usrp object
    usrp_io * usrp = new usrp_io();

    // set properties
    usrp->set_tx_freq(0, tx_freq);
    usrp->set_rx_freq(0, rx_freq);
    usrp->set_tx_decim(0, tx_decim);
    usrp->set_rx_decim(0, rx_decim);

    // start
    usrp->start_tx(0,tx_nco_callback);
    usrp->start_rx(0,rx_display_callback);

    // stop
    usrp->stop_rx(0);
    usrp->stop_tx(0);

    // delete usrp object
    delete usrp;
}

void* tx_nco_callback(short *_I, short *_Q, unsigned int _n, void * _userdata)
{
    return NULL;
}

void* rx_display_callback(short *_I, short *_Q, unsigned int _n, void * _userdata)
{
    return NULL;
}
