#ifndef GLTF_ANIMATION_H
#define GLTF_ANIMATION_H

#include "core/resource.h"


class GLTFAnimation : public Resource {
	GDCLASS(GLTFAnimation, Resource);

protected:
	static void _bind_methods();

public:
	enum Interpolation {
		INTERP_LINEAR,
		INTERP_STEP,
		INTERP_CATMULLROMSPLINE,
		INTERP_CUBIC_SPLINE
	};

	template <class T>
	struct Channel {
		Interpolation interpolation;
		Vector<float> times;
		Vector<T> values;
	};

	struct Track {
		Channel<Vector3> translation_track;
		Channel<Quat> rotation_track;
		Channel<Vector3> scale_track;
		Vector<Channel<float> > weight_tracks;
	};

public:
	bool get_loop() const { return loop; }
	void set_loop(bool p_val) { loop = p_val; }
	Map<int, GLTFAnimation::Track> &get_tracks() { return tracks; }
	GLTFAnimation() {
	}

private:
	bool loop = false;
	Map<int, Track> tracks;
};
#endif