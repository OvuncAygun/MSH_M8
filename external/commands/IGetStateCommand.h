#ifndef IGETSTATECOMMAND_H
#define IGETSTATECOMMAND_H

#include "ICommand.h"
#include "IState.h"

class IGetStateCommand : public ICommand {
public:
    // 1. BURAYA EKLE: Sanal Y�k�c� (Destructor)
    // Bellek s�z�nt�lar�n� �nlemek i�in her komutun kendi sanal y�k�c�s� olmal�d�r.
    virtual ~IGetStateCommand() = 0;

    IState** stateResult; // M8'deki IState* adresi

    virtual void execute() = 0;
};
#endif