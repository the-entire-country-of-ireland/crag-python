# docker build -t fast_braids .
FROM quay.io/pypa/manylinux2014_x86_64

RUN yum clean metadata
RUN yum update -y
RUN yum install -y curl gcc-c++ autoconf git make
RUN yum groupinstall -y 'Development Tools'

ENV PATH /opt/python/cp38-cp38/bin:$PATH
ENV CMAKE_MODULE_PATH /opt/python/cp38-cp38/lib/cmake

RUN pip install cmake

RUN curl -LO https://boostorg.jfrog.io/artifactory/main/release/1.78.0/source/boost_1_78_0.tar.gz && \
	tar xzf ./boost_1_78_0.tar.gz && \
	cd boost_1_78_0 && \
	./bootstrap.sh && \
	./b2 install --with-python --with-program_options --prefix=/opt/python/cp38-cp38 -j4

RUN yum install -y gmp-devel
RUN pip install ninja wheel setuptools

COPY . /crag-python

WORKDIR /crag-python

RUN mkdir wheelhouse

RUN pip wheel -e . -w ./wheelhouse --no-deps && \
	auditwheel repair ./wheelhouse/*.whl
