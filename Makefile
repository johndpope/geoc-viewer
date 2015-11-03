all:
	@echo "Do not run make - run ./setup"

Release.mk:
	qmake CONFIG=release -o Release.mk

Debug.mk:
	qmake CONFIG=debug -o Debug.mk

release: Release.mk
	mkdir -p Release
	${MAKE} -f Release.mk $(args)

debug: Debug.mk
	mkdir -p Debug
	${MAKE} -f Debug.mk $(args)
