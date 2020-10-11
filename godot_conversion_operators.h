#pragma once

namespace godot_conv {

template <class T>
Array to_array(const Vector<T> &p_inp) {
	Array ret;
	for (int i = 0; i < p_inp.size(); i++) {
		ret.push_back(p_inp[i]);
	}
	return ret;
}

template <class T>
Array to_array(const Set<T> &p_inp) {
	Array ret;
	typename Set<T>::Element *elem = p_inp.front();
	while (elem) {
		ret.push_back(elem->get());
		elem = elem->next();
	}
	return ret;
}

template <class T>
void set_from_array(Vector<T>& r_out, const Array& p_inp) {
	r_out.clear();
	for (int i = 0; i < p_inp.size(); i++) {
		r_out.push_back(p_inp[i]);
	}
}

template <class T>
void set_from_array(Set<T>& r_out, const Array& p_inp) {
	r_out.clear();
	for (int i = 0; i < p_inp.size(); i++) {
		r_out.insert(p_inp[i]);
	}
}
template <class K, class V>
Dictionary to_dict(const Map<K, V>& p_inp) {
	Dictionary ret;
	for (typename Map<K, V>::Element *E = p_inp.front(); E; E = E->next()) {
		ret[E->key()] = E->value();
	}
	return ret;
}

template <class K, class V>
void set_from_dict(Map<K, V> &r_out, const Dictionary& p_inp) {
	r_out.clear();
	Array keys = p_inp.keys();
	for (int i = 0; i < keys.size(); i++) {
		r_out[keys[i]] = p_inp[keys[i]];
	}
}

}
