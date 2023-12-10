#pragma once

#include <string>

using std::string;

namespace bld {

	struct LineParameters {
	public:
		string color;  // black, red, green, #34ff23 
		string style;  // - , -- , -* , *
		string weight;  // small, medium, large, x large, xx large

	};

	class PlotBuilder {
	public:
		void addPlot(double *x, double *y, const string& label, const LineParameters& params);
	};

}
