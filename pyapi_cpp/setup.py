from distutils.core import Extension, setup


def main():
    setup(
        name="cppadd",
        version="1.0.0",
        description="cppadd module",
        author="Chris",
        author_email="chrischen3121@gmail.com",
        ext_modules=[Extension("cppadd", ["ext.cpp"])],
    )


if __name__ == "__main__":
    main()
