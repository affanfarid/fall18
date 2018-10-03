JFLAGS = -g
JC = javac
.SUFFIXES: .java .class
.java.class:
	$(JC) $(JFLAGS) $*.java
ALL = Direction.java Place.java Game.java Artifact.java GameTester.java

#default: classes
default: clean jar clear

classes: $(ALL:.java=.class)

#builds jar file
jar: classes
	jar -cvf proj1.jar *.class

clean:
	$(RM) *.class proj1.jar

clear:
	$(RM) *.class