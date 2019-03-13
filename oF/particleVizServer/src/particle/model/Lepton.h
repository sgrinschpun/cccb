#ifndef _Lepton //
#define _Lepton //
#ifdef DEBUG
#define DEBUG_MSG(str) do { std::cout << str << std::endl; } while( false )
#else
#define DEBUG_MSG(str) do { } while ( false )
#endif

#include "ofMain.h"
#include "Model.h"

class Lepton: public Model {
  private:
    void setXMLSettingsName() override;
    void specificParameters() override;

  public:
    Lepton(shared_ptr<ParticleData>& _particleData);
    ~Lepton(){}



};
#endif
