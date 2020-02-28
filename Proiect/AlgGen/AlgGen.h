#ifndef ALGGEN_H

#define ALGGEN_H
class AlgGen {
public:
	virtual void Set_Param(float, float, float, float) = 0;
	virtual void Set_Ref(float) = 0;
	virtual void Eval_Com() = 0;
	virtual float Get_Com() = 0;
};
#endif
