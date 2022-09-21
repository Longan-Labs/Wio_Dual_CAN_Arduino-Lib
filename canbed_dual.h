/*
  canbed_dual.h
  The MIT License (MIT)
  Permission is hereby granted, free of charge, to any person obtaining a copy
  of this software and associated documentation files (the "Software"), to deal
  in the Software without restriction, including without limitation the rights
  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
  copies of the Software, and to permit persons to whom the Software is
  furnished to do so, subject to the following conditions:
  The above copyright notice and this permission notice shall be included in
  all copies or substantial portions of the Software.
  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
  THE SOFTWARE.
*/

#include <Wire.h>
#include <Arduino.h>

#define I2C_ADDR    0X41
#define CANI2C      Wire
#define DELAY_TIME  0

class CANBedDual
{
    private:
    
    unsigned long timerDelay = 0;
    int canNum = 0;
    
    unsigned char canconfig[48];
    
    private:
    
    unsigned long char2long(unsigned char *str);
    void long2char(unsigned long __t, unsigned char *str);
    void makeCanConfig();
    void sendConfig();
    public:
    
    CANBedDual(int num)
    {
        canNum = num;
    }
    
    void init(unsigned long speed);
    void initFD(unsigned long speed20, unsigned long speedfd);
    
    void initMaskFilt(unsigned char num, unsigned char ext, unsigned long mask, unsigned long filt);
    
    void send(unsigned long id, unsigned char ext, unsigned char rtr, unsigned char fd, unsigned char len, unsigned char *dta);
    byte checkRecv();
    byte read(unsigned long *id, int *ext, int *rtr, int *fd, int *len, unsigned char *str);
};