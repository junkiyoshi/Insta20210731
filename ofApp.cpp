#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofSetWindowTitle("openFrameworks");

	ofBackground(239);
	ofSetLineWidth(2);
	ofEnableDepthTest();

	this->line.setMode(ofPrimitiveMode::OF_PRIMITIVE_LINES);
	this->walker.setMode(ofPrimitiveMode::OF_PRIMITIVE_LINES);

	this->base_location_list = vector<glm::vec3>{
		glm::vec3(-300, -300, -300), glm::vec3(300, -300, -300),
		glm::vec3(-300, -300, 300), glm::vec3(300, -300, 300),
		glm::vec3(-300, 300, -300), glm::vec3(300, 300, -300),
		glm::vec3(-300, 300, 300), glm::vec3(300, 300, 300),
	};
}

//--------------------------------------------------------------
void ofApp::update() {

	ofSeedRandom(39);

	this->face.clear();
	this->line.clear();
	this->walker.clear();

	vector<ofColor> base_color_list;
	ofColor color;
	vector<int> hex_list = { 0xef476f, 0xffd166, 0x06d6a0, 0x118ab2, 0x073b4c };
	for (auto hex : hex_list) {

		color.setHex(hex);
		base_color_list.push_back(color);
	}

	int len = 300;
	int size = 15;

	for (int i = 0; i < this->base_location_list.size(); i++) {

		auto base_location = this->base_location_list[i];
		auto noise_param = ofRandom(1000);

		for (int s_1 = len * -0.5; s_1 <= len * 0.5; s_1 += size) {

			for (int s_2 = len * -0.5; s_2 <= len * 0.5; s_2 += size) {

				vector<glm::vec3> vertices;
				auto p = (len + size) * 0.5;

				vertices.clear();
				vertices.push_back(glm::vec3(p, s_1 - size * 0.5, s_2 - size * 0.5));
				vertices.push_back(glm::vec3(p, s_1 + size * 0.5, s_2 - size * 0.5));
				vertices.push_back(glm::vec3(p, s_1 + size * 0.5, s_2 + size * 0.5));
				vertices.push_back(glm::vec3(p, s_1 - size * 0.5, s_2 + size * 0.5));

				auto noise_value = ofNoise(p * 0.003, s_1 * 0.003, s_2 * 0.003, noise_param + ofGetFrameNum() * 0.01);
				auto add = 0;
				if (noise_value > 0.5) {

					add = ofMap(noise_value, 0.5, 1, 0, size * 5);
				}
				for (auto& vertex : vertices) {

					vertex.x += add;
					vertex += base_location;
				}

				this->add_panel(vertices);

				vertices.clear();
				vertices.push_back(glm::vec3(-p, s_1 - size * 0.5, s_2 - size * 0.5));
				vertices.push_back(glm::vec3(-p, s_1 + size * 0.5, s_2 - size * 0.5));
				vertices.push_back(glm::vec3(-p, s_1 + size * 0.5, s_2 + size * 0.5));
				vertices.push_back(glm::vec3(-p, s_1 - size * 0.5, s_2 + size * 0.5));

				noise_value = ofNoise(p * 0.003, s_1 * 0.003, s_2 * 0.003, noise_param + ofGetFrameNum() * 0.01);
				add = 0;
				if (noise_value > 0.5) {

					add = ofMap(noise_value, 0.5, 1, 0, size * 5);
				}
				for (auto& vertex : vertices) {

					vertex.x -= add;
					vertex += base_location;
				}

				this->add_panel(vertices);

				vertices.clear();
				vertices.push_back(glm::vec3(s_1 - size * 0.5, p, s_2 - size * 0.5));
				vertices.push_back(glm::vec3(s_1 + size * 0.5, p, s_2 - size * 0.5));
				vertices.push_back(glm::vec3(s_1 + size * 0.5, p, s_2 + size * 0.5));
				vertices.push_back(glm::vec3(s_1 - size * 0.5, p, s_2 + size * 0.5));

				noise_value = ofNoise(s_1 * 0.003, p * 0.003, s_2 * 0.003, noise_param + ofGetFrameNum() * 0.01);
				add = 0;
				if (noise_value > 0.5) {

					add = ofMap(noise_value, 0.5, 1, 0, size * 5);
				}
				for (auto& vertex : vertices) {

					vertex.y += add;
					vertex += base_location;
				}

				this->add_panel(vertices);

				vertices.clear();
				vertices.push_back(glm::vec3(s_1 - size * 0.5, -p, s_2 - size * 0.5));
				vertices.push_back(glm::vec3(s_1 + size * 0.5, -p, s_2 - size * 0.5));
				vertices.push_back(glm::vec3(s_1 + size * 0.5, -p, s_2 + size * 0.5));
				vertices.push_back(glm::vec3(s_1 - size * 0.5, -p, s_2 + size * 0.5));

				noise_value = ofNoise(s_1 * 0.003, p * 0.003, s_2 * 0.003, noise_param + ofGetFrameNum() * 0.01);
				add = 0;
				if (noise_value > 0.5) {

					add = ofMap(noise_value, 0.5, 1, 0, size * 5);
				}
				for (auto& vertex : vertices) {

					vertex.y -= add;
					vertex += base_location;
				}

				this->add_panel(vertices);

				vertices.clear();
				vertices.push_back(glm::vec3(s_1 - size * 0.5, s_2 - size * 0.5, p));
				vertices.push_back(glm::vec3(s_1 + size * 0.5, s_2 - size * 0.5, p));
				vertices.push_back(glm::vec3(s_1 + size * 0.5, s_2 + size * 0.5, p));
				vertices.push_back(glm::vec3(s_1 - size * 0.5, s_2 + size * 0.5, p));

				noise_value = ofNoise(s_1 * 0.003, s_2 * 0.003, p * 0.003, noise_param + ofGetFrameNum() * 0.01);
				add = 0;
				if (noise_value > 0.5) {

					add = ofMap(noise_value, 0.5, 1, 0, size * 5);
				}
				for (auto& vertex : vertices) {

					vertex.z += add;
					vertex += base_location;
				}

				this->add_panel(vertices);

				vertices.clear();
				vertices.push_back(glm::vec3(s_1 - size * 0.5, s_2 - size * 0.5, -p));
				vertices.push_back(glm::vec3(s_1 + size * 0.5, s_2 - size * 0.5, -p));
				vertices.push_back(glm::vec3(s_1 + size * 0.5, s_2 + size * 0.5, -p));
				vertices.push_back(glm::vec3(s_1 - size * 0.5, s_2 + size * 0.5, -p));

				noise_value = ofNoise(s_1 * 0.003, s_2 * 0.003, p * 0.003, noise_param + ofGetFrameNum() * 0.01);
				add = 0;
				if (noise_value > 0.5) {

					add = ofMap(noise_value, 0.5, 1, 0, size * 5);
				}
				for (auto& vertex : vertices) {

					vertex.z -= add;
					vertex += base_location;
				}

				this->add_panel(vertices);
			}
		}

		int color_index = 0;
		for (int k = 0; k < 10; k++) {

			this->walker.addVertex(this->base_location_list[i] + glm::vec3(
				ofMap(ofNoise(ofRandom(1000), ofGetFrameNum() * 0.005), 0, 1, -100, 100),
				ofMap(ofNoise(ofRandom(1000), ofGetFrameNum() * 0.005), 0, 1, -100, 100),
				ofMap(ofNoise(ofRandom(1000), ofGetFrameNum() * 0.005), 0, 1, -100, 100)
			));

			this->walker.addColor(base_color_list[color_index]);
			color_index = (color_index + 1) % base_color_list.size();
		}
	}

	/*
	for (int k = 0; k < this->walker.getNumVertices(); k++) {

		for (int m = k + 1; m < this->walker.getNumVertices(); m++) {

			if (glm::distance(this->walker.getVertex(k), this->walker.getVertex(m)) < 30) {

				this->walker.addIndex(k);
				this->walker.addIndex(m);
			}
		}
	}
	*/
}

//--------------------------------------------------------------
void ofApp::draw() {

	this->cam.begin();
	ofRotateX(ofGetFrameNum() * 0.37);
	ofRotateY(ofGetFrameNum() * 0.72);

	ofSetColor(239);
	this->face.draw();

	ofSetColor(39);
	this->line.drawWireframe();

	for (int i = 0; i < this->walker.getNumVertices(); i++) {

		ofSetColor(this->walker.getColor(i));
		ofDrawSphere(this->walker.getVertex(i), 30);
	}

	this->cam.end();
}

//--------------------------------------------------------------
void ofApp::add_panel(vector<glm::vec3> vertices) {

	this->face.addVertices(vertices);

	this->face.addIndex(this->face.getNumVertices() - 4); this->face.addIndex(this->face.getNumVertices() - 3); this->face.addIndex(this->face.getNumVertices() - 2);
	this->face.addIndex(this->face.getNumVertices() - 4); this->face.addIndex(this->face.getNumVertices() - 2); this->face.addIndex(this->face.getNumVertices() - 1);

	this->line.addVertices(vertices);

	this->line.addIndex(this->line.getNumVertices() - 4); this->line.addIndex(this->line.getNumVertices() - 3);
	this->line.addIndex(this->line.getNumVertices() - 3); this->line.addIndex(this->line.getNumVertices() - 2);
	this->line.addIndex(this->line.getNumVertices() - 2); this->line.addIndex(this->line.getNumVertices() - 1);
	this->line.addIndex(this->line.getNumVertices() - 1); this->line.addIndex(this->line.getNumVertices() - 4);
}

//--------------------------------------------------------------
glm::vec2 ofApp::make_point(int len, int param) {

	param = param % 100;
	if (param < 25) {

		return glm::vec2(ofMap(param, 0, 25, -len * 0.5, len * 0.5), -len * 0.5);
	}
	else if (param < 50) {

		return glm::vec2(len * 0.5, ofMap(param, 25, 50, -len * 0.5, len * 0.5));
	}
	else if (param < 75) {

		return glm::vec2(ofMap(param, 50, 75, len * 0.5, -len * 0.5), len * 0.5);
	}
	else {

		return glm::vec2(-len * 0.5, ofMap(param, 75, 100, len * 0.5, -len * 0.5));
	}
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}