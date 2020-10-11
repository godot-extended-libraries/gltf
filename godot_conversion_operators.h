#pragma once

namespace godot_conv {

template <class T>
Array to_array(const Vector<T> &inp) {
	Array ret;
	for (int i = 0; i < inp.size(); i++) {
		ret.push_back(inp[i]);
	}
	return ret;
}

template <class T>
Array to_array(const Set<T> &inp) {
	Array ret;
	typename Set<T>::Element *elem = inp.front();
	while (elem) {
		ret.push_back(elem->get());
		elem = elem->next();
	}
	return ret;
}

template <class T>
void set_from_array(Vector<T> &out, const Array &inp) {
	out.clear();
	for (int i = 0; i < inp.size(); i++) {
		out.push_back(inp[i]);
	}
}

template <class T>
void set_from_array(Set<T> &out, const Array &inp) {
	out.clear();
	for (int i = 0; i < inp.size(); i++) {
		out.insert(inp[i]);
	}
}
template <class K, class V>
Dictionary to_dict(const Map<K, V> &inp) {
	Dictionary ret;
	for (Map<K, V>::Element *E = inp.front(); E; E = E->next()) {
		ret[E->key()] = E->value();
	}
	return ret;
}

template <class K, class V>
void set_from_dict(Map<K, V> &out, const Dictionary &inp) {
	out.clear();
	Array keys = inp.keys();
	for (int i = 0; i < keys.size(); i++) {
		out[keys[i]] = inp[keys[i]];
	}
}

}