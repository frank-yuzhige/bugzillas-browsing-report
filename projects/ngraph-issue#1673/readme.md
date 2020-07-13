# ngraph Issue #1673

## THE .ova file is not ready  yet... It's 5GB big and takes forever to upload... Trying other methods to get away with it...

### How to Reproduce the bug
1. Load bug.ova into Oracle Virtualbox VM.

2. Start the VM and login with the following credentials:
```
username: fyu
password: Yzg123456
```
3. Run these commands below:
```bash
$ sudo service docker start
$ cd ngraph/contrib/docker
$ make check_gcc OS=centos7
```

### Changes
The raw code cloned directly from github did not produce the expected output. Several changes have been made to files under `contrib/docker/` to solve this issue, including changes to `Dockerfile`s that specifies the packages' versions which supports python2 for `pip`, and changes to `make-dimage.sh` that makes `docker` happy with the image's tag name. All of these changes should not make any affects to the bug itself.

### Links

__ngraph github repo__: https://github.com/NervanaSystems/ngraph.

__issue page__: https://github.com/NervanaSystems/ngraph/issues/1673.