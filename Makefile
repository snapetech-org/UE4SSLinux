.PHONY: build build-linux build-windows smoke test package clean

build: build-linux

build-linux:
	scripts/build-linux-client-loader.sh
	scripts/build-linux-server-loader.sh

build-windows:
	scripts/build-windows-client-loader.sh

smoke:
	scripts/smoke-linux-client-loader.sh
	scripts/smoke-linux-server-loader.sh

test:
	python3 -m pytest tests

package:
	scripts/package-linux-client-loader.sh
	scripts/package-linux-server-loader.sh
	scripts/package-windows-client-loader.sh

clean:
	rm -rf build dist
