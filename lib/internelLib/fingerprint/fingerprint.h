#include <Arduino.h>
#include <iostream>
class fingerprint
{
private:
    /* data */
public:
    fingerprint();
    void del_finger(int fing_id);
    String reg_storefinger(int id);
    String check_finger(int fing_id);
    void start_fing_sen();
};
