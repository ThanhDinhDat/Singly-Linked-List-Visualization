#include"Project.h"

void main(int argc, char** argv)
{
	HWND hwnd = GetConsoleWindow();
	ShowWindow(hwnd, 0);
	printf("                     SINGLY LINKED LIST                       \n\n");

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowPosition(50, 50);
	glutInitWindowSize(1280, 600);
	main_window = glutCreateWindow("SINGLY LINKED LIST");


	glutDisplayFunc(renderscene);
	GLUI_Master.set_glutIdleFunc(myGlutIdle);
	GLUI_Master.set_glutReshapeFunc(resize);
	GLUI_Master.set_glutKeyboardFunc(MyKeyboard);
	GLUI_Master.set_glutSpecialFunc(NULL);
	GLUI_Master.set_glutMouseFunc(NULL);

	init();

	setupGLUI();

	glutMainLoop();
}