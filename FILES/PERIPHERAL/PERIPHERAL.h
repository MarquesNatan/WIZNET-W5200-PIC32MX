#ifndef PERIPHERAL_H
#define PERIPHERAL_H

void PeripheralInit(void* args);

void SpiSelect(void);
void SpiDeselect(void);

void WiznetReset(void);
void WiznetStart(void);

#endif 