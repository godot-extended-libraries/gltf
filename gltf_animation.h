#pragma once
#include "core/resource.h"


class GLTFAnimation : public Resource {
	GDCLASS(GLTFAnimation, Resource);

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
	void set_loop(bool val) { loop = val; }
	String get_name() const { return name; }
	void set_name(String val) { name = val; }
	Map<int, GLTFAnimation::Track> &get_tracks() { return tracks; }
	GLTFAnimation() {
	}

private:
	bool loop = false;
	String name;
	Map<int, Track> tracks;
};

