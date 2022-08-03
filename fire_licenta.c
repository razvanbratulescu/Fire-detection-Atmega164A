#include <mega164a.h>
#include <stdio.h>
#include <delay.h>  
#include <io.h>
#include <string.h> 
#include <stdlib.h>
#include <stdint.h>
#define DHT11_PIN 2     //pin PC2, 24
uint8_t c = 0; 
uint8_t q;
uint8_t I_RH, D_RH, I_Temp, D_Temp, CheckSum;
int MQ2;
void Request()
{
    DDRC |= (1<<DHT11_PIN);
    PORTC &= ~(1<<DHT11_PIN);    /* set to low pin */
    delay_ms(20);            /* wait for 20ms */
    PORTC |= (1<<DHT11_PIN);    /* set to high pin */
}
void Response()                /* receive response from DHT11 */
{
    DDRC &= ~(1<<DHT11_PIN);
    while(PINC & (1<<DHT11_PIN));
    while((PINC & (1<<DHT11_PIN))==0);
    while(PINC & (1<<DHT11_PIN));
}
uint8_t Receive_data()            /* receive data */
{    
    for (q=0; q<8; q++)
    {
        while((PINC & (1<<DHT11_PIN)) == 0);  /* check received bit 0 or 1 */
        delay_us(30);
        if(PINC & (1<<DHT11_PIN))
        c = (c<<1)|(0x01);    /* then its logic HIGH */
        else            /* otherwise its logic LOW */
        c = (c<<1);
        while(PINC & (1<<DHT11_PIN));
    }
    return c;
}
#define ADC_VREF_TYPE ((0<<REFS1) | (0<<REFS0) | (0<<ADLAR))

unsigned int read_adc(unsigned char adc_input)
{
ADMUX=adc_input | ADC_VREF_TYPE;
delay_us(10);
ADCSRA|=(1<<ADSC);
while ((ADCSRA & (1<<ADIF))==0);
ADCSRA|=(1<<ADIF);
return ADCW;
}

void main(void)
{
#pragma optsize-
CLKPR=(1<<CLKPCE);
CLKPR=(0<<CLKPCE) | (0<<CLKPS3) | (0<<CLKPS2) | (0<<CLKPS1) | (0<<CLKPS0);
#ifdef _OPTIMIZE_SIZE_
#pragma optsize+
#endif
DDRA=(0<<DDA7) | (0<<DDA6) | (0<<DDA5) | (0<<DDA4) | (0<<DDA3) | (0<<DDA2) | (0<<DDA1) | (0<<DDA0);
PORTA=(0<<PORTA7) | (0<<PORTA6) | (0<<PORTA5) | (0<<PORTA4) | (0<<PORTA3) | (0<<PORTA2) | (0<<PORTA1) | (0<<PORTA0);
DDRB=(1<<DDB7) | (1<<DDB6) | (1<<DDB5) | (1<<DDB4) | (1<<DDB3) | (1<<DDB2) | (1<<DDB1) | (1<<DDB0);
PORTB=(0<<PORTB7) | (0<<PORTB6) | (0<<PORTB5) | (0<<PORTB4) | (0<<PORTB3) | (0<<PORTB2) | (0<<PORTB1) | (0<<PORTB0);
DDRC=(0<<DDC7) | (0<<DDC6) | (0<<DDC5) | (0<<DDC4) | (0<<DDC3) | (0<<DDC2) | (0<<DDC1) | (0<<DDC0);
PORTC=(0<<PORTC7) | (0<<PORTC6) | (0<<PORTC5) | (0<<PORTC4) | (0<<PORTC3) | (0<<PORTC2) | (0<<PORTC1) | (0<<PORTC0);
DDRD=(0<<DDD7) | (0<<DDD6) | (0<<DDD5) | (0<<DDD4) | (0<<DDD3) | (0<<DDD2) | (0<<DDD1) | (0<<DDD0);
PORTD=(0<<PORTD7) | (0<<PORTD6) | (0<<PORTD5) | (0<<PORTD4) | (0<<PORTD3) | (0<<PORTD2) | (0<<PORTD1) | (0<<PORTD0);
TCCR0A=(0<<COM0A1) | (0<<COM0A0) | (0<<COM0B1) | (0<<COM0B0) | (0<<WGM01) | (0<<WGM00);
TCCR0B=(0<<WGM02) | (0<<CS02) | (0<<CS01) | (0<<CS00);
TCNT0=0x00;
OCR0A=0x00;
OCR0B=0x00;
TCCR1A=(0<<COM1A1) | (0<<COM1A0) | (0<<COM1B1) | (0<<COM1B0) | (0<<WGM11) | (0<<WGM10);
TCCR1B=(0<<ICNC1) | (0<<ICES1) | (0<<WGM13) | (0<<WGM12) | (0<<CS12) | (0<<CS11) | (0<<CS10);
TCNT1H=0x00;
TCNT1L=0x00;
ICR1H=0x00;
ICR1L=0x00;
OCR1AH=0x00;
OCR1AL=0x00;
OCR1BH=0x00;
OCR1BL=0x00;
ASSR=(0<<EXCLK) | (0<<AS2);
TCCR2A=(0<<COM2A1) | (0<<COM2A0) | (0<<COM2B1) | (0<<COM2B0) | (0<<WGM21) | (0<<WGM20);
TCCR2B=(0<<WGM22) | (0<<CS22) | (0<<CS21) | (0<<CS20);
TCNT2=0x00;
OCR2A=0x00;
OCR2B=0x00;
TIMSK0=(0<<OCIE0B) | (0<<OCIE0A) | (0<<TOIE0);
TIMSK1=(0<<ICIE1) | (0<<OCIE1B) | (0<<OCIE1A) | (0<<TOIE1);
TIMSK2=(0<<OCIE2B) | (0<<OCIE2A) | (0<<TOIE2);
EICRA=(0<<ISC21) | (0<<ISC20) | (0<<ISC11) | (0<<ISC10) | (0<<ISC01) | (0<<ISC00);
EIMSK=(0<<INT2) | (0<<INT1) | (0<<INT0);
PCICR=(0<<PCIE3) | (0<<PCIE2) | (0<<PCIE1) | (0<<PCIE0);
UCSR0A=(0<<RXC0) | (0<<TXC0) | (0<<UDRE0) | (0<<FE0) | (0<<DOR0) | (0<<UPE0) | (0<<U2X0) | (0<<MPCM0);
UCSR0B=(0<<RXCIE0) | (0<<TXCIE0) | (0<<UDRIE0) | (1<<RXEN0) | (1<<TXEN0) | (0<<UCSZ02) | (0<<RXB80) | (0<<TXB80);
UCSR0C=(0<<UMSEL01) | (0<<UMSEL00) | (0<<UPM01) | (0<<UPM00) | (0<<USBS0) | (1<<UCSZ01) | (1<<UCSZ00) | (0<<UCPOL0);
UBRR0H=0x00;
UBRR0L=0x81;
UCSR1B=(0<<RXCIE1) | (0<<TXCIE1) | (0<<UDRIE1) | (0<<RXEN1) | (0<<TXEN1) | (0<<UCSZ12) | (0<<RXB81) | (0<<TXB81);
ACSR=(1<<ACD) | (0<<ACBG) | (0<<ACO) | (0<<ACI) | (0<<ACIE) | (0<<ACIC) | (0<<ACIS1) | (0<<ACIS0);
DIDR1=(0<<AIN0D) | (0<<AIN1D);
DIDR0=(0<<ADC7D) | (0<<ADC6D) | (0<<ADC5D) | (0<<ADC4D) | (0<<ADC3D) | (0<<ADC2D) | (0<<ADC1D) | (0<<ADC0D);
ADMUX=ADC_VREF_TYPE;
ADCSRA=(1<<ADEN) | (0<<ADSC) | (0<<ADATE) | (0<<ADIF) | (0<<ADIE) | (1<<ADPS2) | (0<<ADPS1) | (1<<ADPS0);
ADCSRB=(0<<ADTS2) | (0<<ADTS1) | (0<<ADTS0);
SPCR=(0<<SPIE) | (0<<SPE) | (0<<DORD) | (0<<MSTR) | (0<<CPOL) | (0<<CPHA) | (0<<SPR1) | (0<<SPR0);
TWCR=(0<<TWEA) | (0<<TWSTA) | (0<<TWSTO) | (0<<TWEN) | (0<<TWIE);

    PORTB |=(1<<PORTB5);
    PORTB &=~(1<<PORTB4);
    PORTB &=~(1<<PORTB6);
    PORTB |=(1<<PORTB7);
    while(1)
    {
        MQ2=read_adc(5)   ;
        Request();
        Response();   
        I_RH = Receive_data();
        D_RH = Receive_data();
        I_Temp = Receive_data();
        D_Temp = Receive_data();
        CheckSum = Receive_data(); 
        printf(" T: %d.%dC", I_Temp, D_Temp);   
        printf(" U: %d.%d%% ", I_RH, D_RH);  
        printf(" FUM: %dppm ", MQ2);
            /* Send value to string */
        
        if(I_Temp > 30 || I_RH < 35 || MQ2 > 400)
        {
            /* Buzzer este pornit*/
            PORTB |=(1<<PORTB4);
            PORTB |=(1<<PORTB6);
            delay_ms(2000);
            PORTB &=~(1<<PORTB6);
            PORTB &=~(1<<PORTB5); 
            PORTB &=~(1<<PORTB7);            
            /* Strarea leudului este HIGH*/
        }
        else
        {
            PORTB &=~(1<<PORTB4);
            PORTB &=~(1<<PORTB6);
			PORTB |=(1<<PORTB5);
            PORTB |=(1<<PORTB7);
      
      
        delay_ms(2500);
    }            
}
