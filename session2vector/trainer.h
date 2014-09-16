#ifndef TRAINER_H_
#define TRAINER_H_
#include "utils.h"
#include "vec.h"
#include "vocab.h"
/* 
	���� sin ���й�һ��
*/
class Trainer {
public:
	typedef float value_type;

	Trainer() {}

	Trainer(int len_vec, index_type vocab_size, float alpha=0.01) : \
		len_vec(len_vec), vocab_size(vocab_size), alpha(alpha)
	{
		vocab.init(vocab_size, len_vec, true);
	}

	void init(int len_vec, index_type vocab_size, float alpha=0.01) {
		Trainer(len_vec, vocab_size, alpha);
	}
	
	void train_iter(vector<index_type> &preterms, vector<index_type> &nextterms1, vector<index_type> &nextterms2) {

		value_type exp__dot_xp_xa = exp(-dot(xp, xa));
		value_type tmpa = - exp__dot_xp_xa / pow((1+exp__dot_xp_xa), 2);

	}

protected:
	value_type cost(value_type score1, value_type score2) {
		return 1 - (score1 - score2);
	}

	value_type cal_score(Vec &xp, Vec &x) {
		value_type xp_dot_x = dot(xp, x);
		return 1.0 / ( 1.0 + exp(- xp_dot_x));
	}

	Vec grad(Vec &xp, Vec &xa, Vec &xb) {
	}

private:
	int len_vec;
	int vocab_size;
	float alpha;
	Vocab vocab;
};













#endif