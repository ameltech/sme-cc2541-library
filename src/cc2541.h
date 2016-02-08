/*
 * cc12541.h
 *
 * Created: 01/01/2016 22:14:39
 *  Author: development
 */


#ifndef CC2541_H_
#define CC2541_H_


#define BUFFER_LEN   100

#define TX      1
#define RX      0

    
typedef struct {
    uint8_t idx;
    uint8_t data[BUFFER_LEN];
} bleMsgT;


class Cc2541 {
public:
    Cc2541(void);
    virtual ~Cc2541(){};

private:	

    uint8_t cur_dir;
    uint16_t cur_dir_len; 
    bleMsgT     tx;
    bleMsgT     rx;

    void handleRxData(uint8_t inChar);
	char getRxData(void);
    bool rxDataReady(void);
  
// library API
public:
    bool available();
    char read(void);
    void writeChar(const char data);
    void write(const char *data, char len);
    void begin(void);
};


extern Cc2541  smeBle;

#endif /* CC2541_H_ */
