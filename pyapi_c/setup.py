from distutils.core import Extension, setup


def main():
    setup(
        name="cadd",
        version="1.0.0",
        description="cadd module",
        author="Chris",
        author_email="chrischen3121@gmail.com",
        ext_modules=[Extension("cadd", ["ext.c"])],
    )


if __name__ == "__main__":
    main()
